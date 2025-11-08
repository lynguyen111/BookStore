#pragma once

#include "core/custom/Optional.h"

#include "core/custom/CustomString.h"

#include "core/custom/DynamicArray.h"

#include "model/ReportRequest.h"
#include "repository/ReportRequestRepository.h"

namespace pbl2::service {

class ReportService {
public:
    explicit ReportService(custom::CustomString dataDir);

    custom::DynamicArray<model::ReportRequest> fetchAll() const;
    custom::Optional<model::ReportRequest> findById(const custom::CustomString &requestId) const;

    bool submitRequest(model::ReportRequest request) const;
    bool updateStatus(const custom::CustomString &requestId, const custom::CustomString &status) const;
    bool removeRequest(const custom::CustomString &requestId) const;

private:
    repository::ReportRequestRepository repository;

    [[nodiscard]] custom::DynamicArray<model::ReportRequest> ensureLoaded() const;
    void persist(const custom::DynamicArray<model::ReportRequest> &requests) const;
};

}  // namespace pbl2::service
