#include "service/ReportService.h"

#include "core/DateTime.h"

using namespace std;  // project-wide request

namespace pbl2::service {

ReportService::ReportService(custom::CustomString dataDir) : repository(dataDir) {}

custom::DynamicArray<model::ReportRequest> ReportService::fetchAll() const { return ensureLoaded(); }

custom::Optional<model::ReportRequest> ReportService::findById(const custom::CustomString &requestId) const {
    const custom::CustomString trimmed = requestId.trimmed();
    if (trimmed.isEmpty()) return custom::Optional<model::ReportRequest>();
    const auto requests = ensureLoaded();
    if (requests.isEmpty()) return custom::Optional<model::ReportRequest>();
    for (custom::DynamicArray<model::ReportRequest>::ConstIterator it = requests.cbegin(); it != requests.cend(); ++it) {
        if (it->getRequestId().compare(trimmed, custom::CaseSensitivity::Insensitive) == 0) {
            return custom::Optional<model::ReportRequest>(*it);
        }
    }
    return custom::Optional<model::ReportRequest>();
}

bool ReportService::submitRequest(model::ReportRequest request) const {
    auto requests = ensureLoaded();

    if (request.getRequestId().trimmed().isEmpty()) {
        const auto now = core::DateTime::nowUtc();
        const custom::CustomString timestamp = now.toCompactTimestamp();
        custom::CustomString id(custom::CustomStringLiteral("RR-"));
        id.append(timestamp);
        request.setRequestId(id);
        request.setCreatedAt(now);
    }

    bool exists = false;
    for (custom::DynamicArray<model::ReportRequest>::ConstIterator it = requests.cbegin(); it != requests.cend(); ++it) {
        if (it->getRequestId().compare(request.getRequestId(), custom::CaseSensitivity::Insensitive) == 0) {
            exists = true;
            break;
        }
    }
    if (exists) return false;

    if (!request.getCreatedAt().isValid()) {
        request.setCreatedAt(core::DateTime::nowUtc());
    }
    if (request.getStatus().trimmed().isEmpty()) {
        request.setStatus(custom::CustomStringLiteral("PENDING"));
    }

    requests.pushBack(request);
    persist(requests);
    return true;
}

bool ReportService::updateStatus(const custom::CustomString &requestId, const custom::CustomString &status) const {
    auto requests = ensureLoaded();
    bool changed = false;
    for (custom::DynamicArray<model::ReportRequest>::Iterator it = requests.begin(); it != requests.end(); ++it) {
        if (it->getRequestId().compare(requestId, custom::CaseSensitivity::Insensitive) == 0) {
            const custom::CustomString trimmed = status.trimmed();
            it->setStatus(trimmed.isEmpty() ? it->getStatus() : trimmed.toUpper());
            changed = true;
            break;
        }
    }
    if (!changed) return false;
    persist(requests);
    return true;
}

bool ReportService::removeRequest(const custom::CustomString &requestId) const {
    auto requests = ensureLoaded();
    bool removed = false;
    custom::DynamicArray<model::ReportRequest>::SizeType index = 0U;
    while (index < requests.size()) {
        if (requests[index].getRequestId().compare(requestId, custom::CaseSensitivity::Insensitive) == 0) {
            requests.removeAt(index);
            removed = true;
        } else {
            ++index;
        }
    }
    if (!removed) return false;
    persist(requests);
    return true;
}

custom::DynamicArray<model::ReportRequest> ReportService::ensureLoaded() const {
    return repository.loadAll();
}

void ReportService::persist(const custom::DynamicArray<model::ReportRequest> &requests) const {
    repository.saveAll(requests);
}

}  // namespace pbl2::service
