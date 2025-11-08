#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>

#include <cerrno>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

namespace {

constexpr uint64_t kSeed = 0x9D8F'6A2B'A5C3'4E71ULL;

#pragma pack(push, 1)
struct BinaryHeader {
    uint32_t magic;
    uint16_t version;
    uint16_t type;
    uint32_t recordSize;
    uint32_t count;
};

struct FileHeader {
    uint32_t recordSize;
    uint32_t count;
};

struct DateRecord {
    int32_t year;
    int32_t month;
    int32_t day;
};

struct DateTimeRecord {
    int32_t year;
    int32_t month;
    int32_t day;
    int32_t hour;
    int32_t minute;
    int32_t second;
    int32_t millisecond;
};

struct BookRecord {
    char id[32];
    char title[256];
    char author[128];
    char genre[64];
    char isbn[32];
    DateRecord publishDate;
    int32_t publishYear;
    int32_t quantity;
    char status[32];
    char summary[512];
};

struct ReaderRecord {
    char id[32];
    char fullName[128];
    DateRecord dob;
    uint8_t active;
    char gender[16];
    char email[128];
    char address[256];
    char phone[32];
    char identityCard[32];
    DateRecord createdDate;
    DateRecord expiryDate;
    int32_t totalBorrowed;
    char notes[512];
};

struct LoanRecord {
    char loanId[32];
    char readerId[32];
    char bookId[32];
    DateRecord borrowDate;
    DateRecord dueDate;
    DateRecord returnDate;
    char status[32];
    int32_t fine;
};

struct AccountRecord {
    char id[32];
    char fullName[128];
    DateRecord dob;
    uint8_t active;
    char accountId[32];
    char username[64];
    char passwordHash[128];
    char role[32];
    char employeeId[32];
    DateTimeRecord createdAt;
    DateTimeRecord lastLogin;
};

struct StaffRecord {
    char id[32];
    char fullName[128];
    DateRecord dob;
    uint8_t active;
    char gender[16];
    char email[128];
    char address[256];
    char phone[32];
    DateRecord hireDate;
    char position[64];
    char notes[256];
};

struct ReportRequestRecord {
    char requestId[32];
    char staffUsername[64];
    DateRecord fromDate;
    DateRecord toDate;
    int32_t handledLoans;
    int32_t lostOrDamaged;
    int32_t overdueReaders;
    char notes[256];
    char status[32];
    DateTimeRecord createdAt;
};

struct ConfigRecord {
    int32_t maxBorrowDays;
    int32_t finePerDay;
    int32_t maxBooksPerReader;
};
#pragma pack(pop)

enum class RecordType : uint16_t {
    Books = 1,
    Readers = 2,
    Loans = 3,
    Accounts = 4,
    Staff = 5,
    Reports = 6,
    Config = 7
};

void xorBuffer(uint8_t* data, size_t len) {
    if (!data || len == 0) return;
    uint64_t s = kSeed ^ (static_cast<uint64_t>(len) << 17);
    for (size_t i = 0; i < len; ++i) {
        s ^= s << 7;
        s ^= s >> 9;
        s ^= s << 13;
        data[i] ^= static_cast<uint8_t>(s & 0xFFu);
        s += i + 0x51A5ull;
    }
}

const char* typeName(uint16_t rawType) {
    switch (static_cast<RecordType>(rawType)) {
        case RecordType::Books:   return "Books";
        case RecordType::Readers: return "Readers";
        case RecordType::Loans:   return "Loans";
        case RecordType::Accounts:return "Accounts";
        case RecordType::Staff:   return "Staff";
        case RecordType::Reports: return "ReportRequests";
        case RecordType::Config:  return "Config";
        default:                  return "Unknown";
    }
}

size_t expectedRecordSize(uint16_t rawType) {
    switch (static_cast<RecordType>(rawType)) {
        case RecordType::Books:   return sizeof(BookRecord);
        case RecordType::Readers: return sizeof(ReaderRecord);
        case RecordType::Loans:   return sizeof(LoanRecord);
        case RecordType::Accounts:return sizeof(AccountRecord);
        case RecordType::Staff:   return sizeof(StaffRecord);
        case RecordType::Reports: return sizeof(ReportRequestRecord);
        case RecordType::Config:  return sizeof(ConfigRecord);
        default:                  return 0;
    }
}

bool readFile(const fs::path& path, std::vector<uint8_t>& out) {
    FILE* file = std::fopen(path.c_str(), "rb");
    if (!file) {
        std::perror("fopen");
        return false;
    }

    if (std::fseek(file, 0, SEEK_END) != 0) {
        std::perror("fseek");
        std::fclose(file);
        return false;
    }
    long size = std::ftell(file);
    if (size < 0) {
        std::perror("ftell");
        std::fclose(file);
        return false;
    }
    if (std::fseek(file, 0, SEEK_SET) != 0) {
        std::perror("fseek");
        std::fclose(file);
        return false;
    }

    out.resize(static_cast<size_t>(size));
    if (size > 0) {
        const size_t read = std::fread(out.data(), 1, out.size(), file);
        if (read != out.size()) {
            std::perror("fread");
            std::fclose(file);
            return false;
        }
    }
    std::fclose(file);
    return true;
}

bool writeFile(const fs::path& path, const uint8_t* data, size_t size) {
    FILE* file = std::fopen(path.c_str(), "wb");
    if (!file) {
        std::perror("fopen");
        return false;
    }
    const size_t written = std::fwrite(data, 1, size, file);
    std::fclose(file);
    if (written != size) {
        std::cerr << "Failed to write full output file\n";
        return false;
    }
    return true;
}

bool isAlreadyConverted(const std::vector<uint8_t>& buffer) {
    if (buffer.size() < sizeof(FileHeader)) return false;
    const FileHeader* header = reinterpret_cast<const FileHeader*>(buffer.data());
    const uint32_t recordSize = header->recordSize;
    const uint32_t count = header->count;
    const size_t payload = static_cast<size_t>(recordSize) * count;
    return sizeof(FileHeader) + payload == buffer.size();
}

}  // namespace

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: convert_legacy_bin <legacy_input> <output>\n";
        std::cerr << "       Add --in-place as the third argument to overwrite the input file.\n";
        return 1;
    }

    const fs::path inputPath = argv[1];
    fs::path outputPath = argv[2];
    const bool inPlace = (argc >= 4 && std::string(argv[3]) == "--in-place") ||
                         (inputPath == outputPath);

    std::vector<uint8_t> buffer;
    if (!readFile(inputPath, buffer)) {
        std::cerr << "Failed to read input file: " << inputPath << "\n";
        return 2;
    }

    if (buffer.empty()) {
        std::cerr << "Input file is empty: " << inputPath << "\n";
        return 2;
    }

    if (isAlreadyConverted(buffer)) {
        std::cerr << "File already appears to use the new BinaryFileStore format. Skipping.\n";
        return 0;
    }

    xorBuffer(buffer.data(), buffer.size());

    if (buffer.size() < sizeof(BinaryHeader)) {
        std::cerr << "Legacy file too small to contain header.\n";
        return 2;
    }

    BinaryHeader legacyHeader{};
    std::memcpy(&legacyHeader, buffer.data(), sizeof(legacyHeader));

    if (legacyHeader.magic != 0xDEADBEEF || legacyHeader.version != 1) {
        std::cerr << "Legacy header validation failed (magic/version mismatch).\n";
        return 2;
    }

    const size_t expectedSize = expectedRecordSize(legacyHeader.type);
    if (expectedSize == 0) {
        std::cerr << "Unknown record type: " << legacyHeader.type << "\n";
        return 2;
    }

    if (legacyHeader.recordSize != expectedSize) {
        std::cerr << "Record size mismatch for type " << typeName(legacyHeader.type)
                  << " (header " << legacyHeader.recordSize
                  << ", expected " << expectedSize << ").\n";
    }

    const size_t payloadSize = static_cast<size_t>(legacyHeader.recordSize) *
                               static_cast<size_t>(legacyHeader.count);
    if (sizeof(BinaryHeader) + payloadSize != buffer.size()) {
        std::cerr << "Legacy file size mismatch; payload does not align with header metadata.\n";
        return 2;
    }

    FileHeader newHeader{
        legacyHeader.recordSize,
        legacyHeader.count
    };

    std::vector<uint8_t> output(sizeof(newHeader) + payloadSize);
    std::memcpy(output.data(), &newHeader, sizeof(newHeader));
    if (payloadSize > 0) {
        std::memcpy(output.data() + sizeof(newHeader),
                    buffer.data() + sizeof(BinaryHeader),
                    payloadSize);
    }

    fs::path finalOutput = outputPath;
    fs::path tempPath = outputPath;

    if (inPlace) {
        tempPath = inputPath;
        tempPath += ".converted";
    }

    if (!writeFile(tempPath, output.data(), output.size())) {
        std::cerr << "Failed to write converted file.\n";
        if (inPlace && fs::exists(tempPath)) {
            fs::remove(tempPath);
        }
        return 2;
    }

    if (inPlace) {
        std::error_code ec;
        fs::rename(tempPath, inputPath, ec);
        if (ec) {
            std::cerr << "Failed to replace original file: " << ec.message() << "\n";
            return 2;
        }
        std::cout << "Converted " << inputPath << " in place (" << typeName(legacyHeader.type)
                  << ", " << legacyHeader.count << " records).\n";
    } else {
        std::cout << "Converted " << inputPath << " -> " << outputPath << " ("
                  << typeName(legacyHeader.type) << ", " << legacyHeader.count
                  << " records).\n";
    }

    return 0;
}

