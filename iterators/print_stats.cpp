#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintStats(vector<Person> persons) {
    sort(persons.begin(), persons.end(), [](const Person& lhs, const Person& rhs) {return lhs.age < rhs.age;});
    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
    auto it = partition(persons.begin(), persons.end(), [](const Person& person) {return person.gender == Gender::FEMALE;});
    sort(persons.begin(), it, [](const Person& lhs, const Person& rhs) {return lhs.age < rhs.age;});
    cout << "Median age for females = " << ComputeMedianAge(persons.begin(), it) << endl;
    it = partition(persons.begin(), persons.end(), [](const Person& person) {return person.gender == Gender::MALE;});
    sort(persons.begin(), it, [](const Person& lhs, const Person& rhs) {return lhs.age < rhs.age;});
    cout << "Median age for males = " << ComputeMedianAge(persons.begin(), it) << endl;
    it = partition(persons.begin(), persons.end(), [](const Person& person) {return person.gender == Gender::FEMALE && person.is_employed;});
    sort(persons.begin(), it, [](const Person& lhs, const Person& rhs) {return lhs.age < rhs.age;});
    cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), it) << endl;
    it = partition(persons.begin(), persons.end(), [](const Person& person) {return person.gender == Gender::FEMALE && !person.is_employed;});
    sort(persons.begin(), it, [](const Person& lhs, const Person& rhs) {return lhs.age < rhs.age;});
    cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), it) << endl;
    it = partition(persons.begin(), persons.end(), [](const Person& person) {return person.gender == Gender::MALE && person.is_employed;});
    sort(persons.begin(), it, [](const Person& lhs, const Person& rhs) {return lhs.age < rhs.age;});
    cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), it) << endl;
    it = partition(persons.begin(), persons.end(), [](const Person& person) {return person.gender == Gender::MALE && !person.is_employed;});
    sort(persons.begin(), it, [](const Person& lhs, const Person& rhs) {return lhs.age < rhs.age;});
    cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(), it) << endl;
}

int main() {
    return 0;
}
