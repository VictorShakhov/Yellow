#include <sstream>
#include <iostream>
#include <string>
#include <iterator>
#include <exception>
#include <algorithm>

#include "date.h"
#include "database.h"

using namespace std;

ostream& operator<<(ostream& os, const pair<Date, string>& p) {
    os << p.first << " " << p.second;
    return os;
}

void Database::Add(const Date& date, const string& event) {
    if(data_base_set[date].count(event) == 0) {
        data_base_set[date].insert(event);
        data_base_vector[date].push_back(event);
    }
}

void Database::Print(ostream& os) const {
    for(const auto& d : data_base_vector) {
        for(const auto& e : d.second) {
            os << d.first << " " << e << endl;
        }
    }
}


pair<Date, string> Database::Last(const Date& date) const {
    if(data_base_vector.upper_bound(date) == data_base_vector.begin()) {
        throw invalid_argument("");
    }
    pair<Date, vector<string>> date_less = *(prev(data_base_vector.upper_bound(date)));
    pair<Date, string> last_event_of_date = make_pair(date_less.first, *date_less.second.rbegin());
    return last_event_of_date;
}

vector<pair<Date, string>> Database::FindIf(function<bool(Date, string)> predicate) const {
    vector<pair<Date, string>> founded_events;
    for(const auto& d : data_base_vector) {
        for(const auto& e : d.second) {
            if(predicate(d.first, e)) {
                founded_events.push_back(make_pair(d.first, e));
            }
        }
    }
    return founded_events;
}

int Database::RemoveIf(function<bool(Date, string)> predicate) {
    int deleted_counter = 0;
    map<Date, set<string>> new_data_base_set;
    map<Date, vector<string>> new_data_base_vector;
    for(auto d : data_base_vector) {
        for(auto e : d.second) {
            if(!predicate(d.first, e)) {
                new_data_base_set[d.first].insert(e);
                new_data_base_vector[d.first].push_back(e);
            } else {
                deleted_counter++;
            }
        }
    }
    data_base_set = new_data_base_set;
    data_base_vector = new_data_base_vector;
    return deleted_counter;
}

