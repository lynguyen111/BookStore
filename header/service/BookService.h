#pragma once

#include "core/custom/Optional.h"

#include "core/custom/CustomString.h"

#include "core/custom/DynamicArray.h"

#include "model/Book.h"
#include "repository/BooksRepository.h"

namespace pbl2::service {

class BookService {
public:
    explicit BookService(custom::CustomString dataDir);

    custom::DynamicArray<model::Book> fetchAll() const;
    custom::Optional<model::Book> findById(const custom::CustomString &bookId) const;
    bool addBook(const model::Book &book) const;
    bool updateBook(const model::Book &book) const;
    bool removeBook(const custom::CustomString &bookId) const;
    bool adjustQuantity(const custom::CustomString &bookId, int delta) const;

private:
    repository::BooksRepository repository;

    [[nodiscard]] custom::DynamicArray<model::Book> ensureLoaded() const;
    void persist(const custom::DynamicArray<model::Book> &books) const;
    static bool normalizeAvailability(model::Book &book);
};

}  // namespace service
