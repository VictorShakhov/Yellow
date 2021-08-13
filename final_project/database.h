#pragma once

#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <functional>

#include "date.h"

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);

    void Print(ostream& os) const;

    int RemoveIf(function<bool(Date, string)> predicate);

    vector<pair<Date, string>> FindIf(function<bool(Date, string)> predicate) const;

    pair<Date, string> Last(const Date& date) const;

private:
    map<Date, set<string>> data_base_set;
    map<Date, vector<string>> data_base_vector;
};

ostream& operator<<(ostream& os, const pair<Date, string>& p);

