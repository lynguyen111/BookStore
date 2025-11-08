#include "core/PathUtils.h"

#include <string>
#include <system_error>

namespace pbl2::core::path {

namespace {

custom::CustomString fromStdString(const std::string &value) {
    if (value.empty()) return custom::CustomString();
    return custom::CustomString(value.c_str(), static_cast<custom::CustomString::SizeType>(value.size()));
}

}  // namespace

std::filesystem::path toFilesystemPath(const custom::CustomString &value) {
    if (value.isEmpty()) return std::filesystem::path();
    return std::filesystem::path(value.cStr());
}

custom::CustomString fromFilesystemPath(const std::filesystem::path &value) {
    const std::string converted = value.string();
    return fromStdString(converted);
}

custom::CustomString join(const custom::CustomString &base, const custom::CustomString &child) {
    const std::filesystem::path combined = toFilesystemPath(base) / toFilesystemPath(child);
    return fromFilesystemPath(combined);
}

bool exists(const custom::CustomString &path) {
    std::error_code ec;
    const bool present = std::filesystem::exists(toFilesystemPath(path), ec);
    return !ec && present;
}

bool ensureDirectory(const custom::CustomString &path) {
    std::error_code ec;
    const std::filesystem::path fsPath = toFilesystemPath(path);
    if (fsPath.empty()) return false;
    if (std::filesystem::exists(fsPath, ec)) {
        return !ec;
    }
    std::filesystem::create_directories(fsPath, ec);
    return !ec;
}

}  // namespace pbl2::core::path
