#pragma once

#include <sstream>

using namespace std;

class Date {
public:
    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;

    void SetYear(int year_);

    void SetMonth(int month_);

    void SetDay(int day_);

private:
    int year;
    int month;
    int day;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& os, const Date& date);

bool operator<(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

