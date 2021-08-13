#include "date.h"

#include <sstream>
#include <iomanip>

using namespace std;

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

void Date::SetYear(int year_) {
    year = year_;
}

void Date::SetMonth(int month_) {
    month = month_;
}

void Date::SetDay(int day_) {
    day = day_;
}

Date ParseDate(istream& is) {
    Date date;
    int year, month, day;
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;
    date.SetYear(year);
    date.SetMonth(month);
    date.SetDay(day);
    return date;
}

ostream& operator<<(ostream& os, const Date& date) {
    os.fill('0');
    os << setw(4) << date.GetYear() << "-" << setw(2) << date.GetMonth() << "-" << setw(2) << date.GetDay();
    return os;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if(lhs.GetYear() == rhs.GetYear()) {
        if(lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

bool operator<=(const Date& lhs, const Date& rhs) {
    if(lhs.GetYear() == rhs.GetYear()) {
        if(lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() <= rhs.GetDay();
        }
        return lhs.GetMonth() <= rhs.GetMonth();
    }
    return lhs.GetYear() <= rhs.GetYear();
}

bool operator>(const Date& lhs, const Date& rhs) {
    if(lhs.GetYear() == rhs.GetYear()) {
        if(lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() > rhs.GetDay();
        }
        return lhs.GetMonth() > rhs.GetMonth();
    }
    return lhs.GetYear() > rhs.GetYear();
}

bool operator>=(const Date& lhs, const Date& rhs) {
    if(lhs.GetYear() == rhs.GetYear()) {
        if(lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() >= rhs.GetDay();
        }
        return lhs.GetMonth() >= rhs.GetMonth();
    }
    return lhs.GetYear() >= rhs.GetYear();
}

bool operator==(const Date& lhs, const Date& rhs) {
    return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return lhs.GetYear() != rhs.GetYear() || lhs.GetMonth() != rhs.GetMonth() || lhs.GetDay() != rhs.GetDay();
}
