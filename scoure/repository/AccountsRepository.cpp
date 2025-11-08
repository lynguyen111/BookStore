#include "repository/AccountsRepository.h"

#include "datafile/BinaryFileStore.h"
#include "core/PathUtils.h"

using namespace std;  // project-wide request

namespace pbl2::repository {

AccountsRepository::AccountsRepository(custom::CustomString dataDir)
    : dataPath(core::path::join(dataDir, custom::CustomStringLiteral("users.bin"))) {}

custom::DynamicArray<model::Account> AccountsRepository::loadAll() const {
    return serialization::BinaryFileStore::readAccounts(dataPath);
}

void AccountsRepository::saveAll(const custom::DynamicArray<model::Account> &accounts) const {
    serialization::BinaryFileStore::writeAccounts(accounts, dataPath);
}

custom::Optional<model::Account> AccountsRepository::findByUsername(const custom::CustomString &username) const {
    const custom::CustomString trimmed = username.trimmed();
    if (trimmed.isEmpty()) return custom::Optional<model::Account>();
    const custom::DynamicArray<model::Account> accounts = loadAll();
    for (custom::DynamicArray<model::Account>::ConstIterator it = accounts.cbegin(); it != accounts.cend(); ++it) {
        if (it->getUsername().compare(trimmed, custom::CaseSensitivity::Insensitive) == 0) {
            return custom::Optional<model::Account>(*it);
        }
    }
    return custom::Optional<model::Account>();
}

custom::CustomString AccountsRepository::hashPassword(const custom::CustomString &plainText) {
    // Simple password storage - just return plaintext
    return plainText;
}

}  // namespace pbl2::repository
