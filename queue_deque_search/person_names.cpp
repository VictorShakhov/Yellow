#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

string FindNameByYear(int year, const map<int, string>& names) {
    auto it_after = names.upper_bound(year);
    string name;
    if(it_after != names.begin()) {
        name = prev(it_after)->second;
    }
    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) {
        const string first_name = FindNameByYear(year, first_names);
        const string last_name = FindNameByYear(year, last_names);
        if(first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if(first_name.empty()) {
            return last_name + " with unknown first name";
        } else if(last_name.empty()) {
            return first_name + " with unknown last name";
        } else {
            return first_name + " " + last_name;
        }
    }

private:
    map<int, string> first_names, last_names;
};
