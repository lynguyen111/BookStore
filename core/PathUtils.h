#pragma once

#include "core/custom/CustomString.h"

#include <filesystem>

namespace pbl2::core::path {

std::filesystem::path toFilesystemPath(const custom::CustomString &value);
custom::CustomString fromFilesystemPath(const std::filesystem::path &value);
custom::CustomString join(const custom::CustomString &base, const custom::CustomString &child);
bool exists(const custom::CustomString &path);
bool ensureDirectory(const custom::CustomString &path);

}  // namespace pbl2::core::path
