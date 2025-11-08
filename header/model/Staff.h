#pragma once

#include "core/Date.h"
#include "core/custom/CustomString.h"

#include "Person.h"

namespace pbl2::model {

struct Staff : Person {
public:
    ~Staff() override = default;

    const custom::CustomString &getGender() const;
    void setGender(const custom::CustomString &value);

    const custom::CustomString &getEmail() const;
    void setEmail(const custom::CustomString &value);

    const custom::CustomString &getAddress() const;
    void setAddress(const custom::CustomString &value);

    const custom::CustomString &getPhone() const;
    void setPhone(const custom::CustomString &value);

    const core::Date &getHireDate() const;
    void setHireDate(const core::Date &value);

    const custom::CustomString &getPosition() const;
    void setPosition(const custom::CustomString &value);

    const custom::CustomString &getNotes() const;
    void setNotes(const custom::CustomString &value);

private:
    custom::CustomString gender;
    custom::CustomString email;
    custom::CustomString address;
    custom::CustomString phone;
    core::Date hireDate;
    custom::CustomString position;
    custom::CustomString notes;
};

}  // namespace pbl2::model
