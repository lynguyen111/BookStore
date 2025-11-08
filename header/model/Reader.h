#pragma once

#include "core/Date.h"
#include "core/custom/CustomString.h"
#include "Person.h"

namespace pbl2::model {

struct Reader : Person {
public:
    ~Reader() override = default;

    const custom::CustomString &getGender() const;
    void setGender(const custom::CustomString &value);

    const custom::CustomString &getEmail() const;
    void setEmail(const custom::CustomString &value);

    const custom::CustomString &getAddress() const;
    void setAddress(const custom::CustomString &value);

    const custom::CustomString &getPhone() const;
    void setPhone(const custom::CustomString &value);

    const custom::CustomString &getIdentityCard() const;
    void setIdentityCard(const custom::CustomString &value);

    const core::Date &getCreatedDate() const;
    void setCreatedDate(const core::Date &value);

    const core::Date &getExpiryDate() const;
    void setExpiryDate(const core::Date &value);

    int getTotalBorrowed() const;
    void setTotalBorrowed(int value);

    const custom::CustomString &getNotes() const;
    void setNotes(const custom::CustomString &value);

private:
    custom::CustomString gender;
    custom::CustomString email;
    custom::CustomString address;
    custom::CustomString phone;
    custom::CustomString identityCard;
    core::Date createdDate;
    core::Date expiryDate;
    int totalBorrowed{0};
    custom::CustomString notes;
};

}  // namespace model


