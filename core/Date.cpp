#include "core/Date.h"

using namespace std;  // project-wide request

namespace pbl2::core {

namespace {

bool isDigit(char c) { return c >= '0' && c <= '9'; }

int parseNumber(const char *data, int length) {
    int value = 0;
    for (int i = 0; i < length; ++i) {
        if (!isDigit(data[i])) return -1;
        value = value * 10 + (data[i] - '0');
    }
    return value;
}

}  // namespace

Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {}

bool Date::isValid() const {
    if (year_ <= 0 || month_ <= 0 || day_ <= 0) return false;
    if (month_ > 12) return false;
    const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month_ - 1];
    const bool leap = (year_ % 4 == 0 && (year_ % 100 != 0 || year_ % 400 == 0));
    if (month_ == 2 && leap) {
        maxDay = 29;
    }
    return day_ <= maxDay;
}

Date Date::fromIsoString(const custom::CustomString &text) {
    if (text.length() != 10U) return Date();
    const char *data = text.cStr();
    if (data[4] != '-' || data[7] != '-') return Date();
    const int year = parseNumber(data, 4);
    const int month = parseNumber(data + 5, 2);
    const int day = parseNumber(data + 8, 2);
    if (year <= 0 || month <= 0 || day <= 0) return Date();
    return Date(year, month, day);
}

custom::CustomString Date::toIsoString() const {
    if (!isValid()) return custom::CustomString();
    char buffer[11];
    buffer[0] = static_cast<char>('0' + (year_ / 1000) % 10);
    buffer[1] = static_cast<char>('0' + (year_ / 100) % 10);
    buffer[2] = static_cast<char>('0' + (year_ / 10) % 10);
    buffer[3] = static_cast<char>('0' + year_ % 10);
    buffer[4] = '-';
    buffer[5] = static_cast<char>('0' + (month_ / 10) % 10);
    buffer[6] = static_cast<char>('0' + month_ % 10);
    buffer[7] = '-';
    buffer[8] = static_cast<char>('0' + (day_ / 10) % 10);
    buffer[9] = static_cast<char>('0' + day_ % 10);
    buffer[10] = '\0';
    return custom::CustomString(buffer);
}

}  // namespace pbl2::core

