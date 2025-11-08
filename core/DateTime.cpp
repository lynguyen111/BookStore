#include "core/DateTime.h"

#include <chrono>
#include <ctime>
#include <cstdio>

using namespace std;  // project-wide request

namespace pbl2::core {
namespace {

bool isLeap(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysInMonth(int year, int month) {
    static const int table[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12) return 0;
    if (month == 2 && isLeap(year)) return 29;
    return table[month - 1];
}

int parseNumber(const char *data, int length) {
    int value = 0;
    for (int i = 0; i < length; ++i) {
        const char ch = data[i];
        if (ch < '0' || ch > '9') return -1;
        value = value * 10 + (ch - '0');
    }
    return value;
}

}  // namespace

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second, int millisecond)
    : year_(year),
      month_(month),
      day_(day),
      hour_(hour),
      minute_(minute),
      second_(second),
      millisecond_(millisecond) {}

bool DateTime::isValid() const {
    if (year_ <= 0 || month_ <= 0 || day_ <= 0) return false;
    if (hour_ < 0 || hour_ > 23) return false;
    if (minute_ < 0 || minute_ > 59) return false;
    if (second_ < 0 || second_ > 59) return false;
    if (millisecond_ < 0 || millisecond_ > 999) return false;
    const int dim = daysInMonth(year_, month_);
    if (dim == 0 || day_ > dim) return false;
    return true;
}

void DateTime::clear() {
    year_ = month_ = day_ = hour_ = minute_ = second_ = millisecond_ = 0;
}

custom::CustomString DateTime::toIsoString() const {
    if (!isValid()) return custom::CustomString();
    char buffer[32];
    const int written = snprintf(buffer,
                                 sizeof(buffer),
                                 "%04d-%02d-%02dT%02d:%02d:%02d%s%03dZ",
                                 year_,
                                 month_,
                                 day_,
                                 hour_,
                                 minute_,
                                 second_,
                                 millisecond_ > 0 ? "." : "",
                                 millisecond_);
    if (written <= 0) return custom::CustomString();
    if (millisecond_ == 0) {
        // Remove the extra digits introduced by conditional formatting when ms == 0.
        char simple[21];
        snprintf(simple, sizeof(simple), "%04d-%02d-%02dT%02d:%02d:%02dZ", year_, month_, day_, hour_, minute_, second_);
        return custom::CustomString(simple);
    }
    return custom::CustomString(buffer);
}

custom::CustomString DateTime::toCompactTimestamp() const {
    if (!isValid()) return custom::CustomString();
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%04d%02d%02d%02d%02d%02d%03d", year_, month_, day_, hour_, minute_, second_, millisecond_);
    return custom::CustomString(buffer);
}

DateTime DateTime::nowUtc() {
    const auto now = chrono::system_clock::now();
    const auto nowMs = chrono::time_point_cast<chrono::milliseconds>(now);
    const auto millis = nowMs.time_since_epoch();
    const auto secs = chrono::duration_cast<chrono::seconds>(millis);
    const int millisecondPart = static_cast<int>((millis - secs).count());
    const time_t seconds = chrono::system_clock::to_time_t(nowMs);
    struct tm tmValue {};
#if defined(_WIN32)
    gmtime_s(&tmValue, &seconds);
#else
    gmtime_r(&seconds, &tmValue);
#endif
    return DateTime(tmValue.tm_year + 1900,
                    tmValue.tm_mon + 1,
                    tmValue.tm_mday,
                    tmValue.tm_hour,
                    tmValue.tm_min,
                    tmValue.tm_sec,
                    millisecondPart);
}

DateTime DateTime::fromIsoString(const custom::CustomString &text) {
    if (text.isEmpty()) return DateTime();
    const char *data = text.cStr();
    const int length = static_cast<int>(text.length());
    if (length < 19) return DateTime();
    if (data[4] != '-' || data[7] != '-' || (data[10] != 'T' && data[10] != 't') || data[13] != ':' || data[16] != ':') {
        return DateTime();
    }
    const int year = parseNumber(data, 4);
    const int month = parseNumber(data + 5, 2);
    const int day = parseNumber(data + 8, 2);
    const int hour = parseNumber(data + 11, 2);
    const int minute = parseNumber(data + 14, 2);
    const int second = parseNumber(data + 17, 2);
    if (year <= 0 || month <= 0 || day <= 0 || hour < 0 || minute < 0 || second < 0) return DateTime();
    int millisecond = 0;
    int index = 19;
    if (index < length && data[index] == '.') {
        ++index;
        int digits = 0;
        int value = 0;
        while (index < length && digits < 3 && data[index] >= '0' && data[index] <= '9') {
            value = value * 10 + (data[index] - '0');
            ++index;
            ++digits;
        }
        while (digits < 3) {
            value *= 10;
            ++digits;
        }
        millisecond = value;
    }
    // Skip timezone information if present.
    // Accept trailing Z or offsets without adjusting the stored value.
    return DateTime(year, month, day, hour, minute, second, millisecond);
}

}  // namespace pbl2::core
