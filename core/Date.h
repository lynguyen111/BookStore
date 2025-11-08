#pragma once

#include "core/custom/CustomString.h"

namespace pbl2::core{

class Date {
public:
    Date() = default;
    Date(int year, int month, int day);

    int year() const { return year_; }
    int month() const { return month_; }
    int day() const { return day_; }

    void setYear(int value) { year_ = value; }
    void setMonth(int value) { month_ = value; }
    void setDay(int value) { day_ = value; }

    bool isValid() const;

    static Date fromIsoString(const custom::CustomString &text);
    custom::CustomString toIsoString() const;

private:
    int year_{0};
    int month_{0};
    int day_{0};
};

}  // namespace core


