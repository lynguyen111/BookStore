#pragma once


namespace pbl2::model {

class SystemConfig {
public:
    int getMaxBorrowDays() const { return maxBorrowDays; }
    void setMaxBorrowDays(int value) { maxBorrowDays = value; }

    int getFinePerDay() const { return finePerDay; }
    void setFinePerDay(int value) { finePerDay = value; }

    int getMaxBooksPerReader() const { return maxBooksPerReader; }
    void setMaxBooksPerReader(int value) { maxBooksPerReader = value; }

private:
    int maxBorrowDays{0};
    int finePerDay{0};
    int maxBooksPerReader{0};
};

}  // namespace model


