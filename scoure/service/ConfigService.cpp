#include "service/ConfigService.h"

using namespace std;  // project-wide request

namespace pbl2::service {

ConfigService::ConfigService(custom::CustomString dataDir) : repository(dataDir) {}

model::SystemConfig ConfigService::load() const { return repository.load(); }

bool ConfigService::save(const model::SystemConfig &config) const {
    repository.save(config);
    return true;
}

bool ConfigService::updateLimits(int maxBorrowDays, int finePerDay, int maxBooksPerReader) const {
    auto config = repository.load();
    if (maxBorrowDays > 0) config.setMaxBorrowDays(maxBorrowDays);
    if (finePerDay >= 0) config.setFinePerDay(finePerDay);
    if (maxBooksPerReader > 0) config.setMaxBooksPerReader(maxBooksPerReader);
    repository.save(config);
    return true;
}

}  // namespace pbl2::service
