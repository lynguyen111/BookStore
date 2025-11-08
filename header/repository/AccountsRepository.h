#pragma once

#include "core/custom/Optional.h"

#include "core/custom/CustomString.h"
#include "core/custom/DynamicArray.h"

#include "model/Account.h"

namespace pbl2::repository {

class AccountsRepository {
public:
    explicit AccountsRepository(custom::CustomString dataDir);

    [[nodiscard]] custom::DynamicArray<model::Account> loadAll() const;
    void saveAll(const custom::DynamicArray<model::Account> &accounts) const;
    [[nodiscard]] custom::Optional<model::Account> findByUsername(const custom::CustomString &username) const;
    [[nodiscard]] static custom::CustomString hashPassword(const custom::CustomString &plainText);

private:
    custom::CustomString dataPath;
};

}  // namespace pbl2::repository
