#pragma once

#include "core/custom/CustomString.h"

#include "SystemConfig.h"
#include "repository/ConfigRepository.h"

namespace pbl2::service {

class ConfigService {
public:
    explicit ConfigService(custom::CustomString dataDir);

    model::SystemConfig load() const;
    bool save(const model::SystemConfig &config) const;
    bool updateLimits(int maxBorrowDays, int finePerDay, int maxBooksPerReader) const;

private:
    repository::ConfigRepository repository;
};

}  // namespace pbl2::service
