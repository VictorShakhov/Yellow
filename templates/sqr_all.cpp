#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <typeinfo>
#include <exception>

using namespace std;

template<typename T> vector<T> Sqr (vector<T> v);
template<typename First, typename Second> pair<First, Second> Sqr(pair<First, Second> p);
template<typename Key, typename Value> map<Key, Value> Sqr(map<Key, Value> m);
template<typename Value> Value Sqr(Value n);

template<typename T>
vector<T> Sqr(vector<T> v) {
    vector<T> result;
    for(auto elem : v) {
        result.push_back(Sqr(elem));
    }
    return result;
}

template<typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> p) {
    return {Sqr(p.first), Sqr(p.second)};
}

template<typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value> m) {
    map<Key, Value> result;
    for(auto elem : m) {
        result[elem.first] = Sqr(elem.second);
    }
    return result;
}

template<typename Value>
Value Sqr(Value n) {
    return n * n;
}


int main() {
    {
        int n = 5;
        if(Sqr<int>(5) != 25) {
            throw runtime_error("Wrong int");
        }
    }


    {
        pair<int, int> n = {2, 3};
        if(Sqr(n) != make_pair(4, 9)) {
            throw runtime_error("Wrong pair");
        }
    }

    {
        vector<int> n = {2, 3, 4}, result = {4, 9, 16};
        if(Sqr(n) != result) {
            throw runtime_error("Wrong vector");
        }
    }

    {
        map<int, int> n = {{2, 3}, {4, 5}}, result = {{2, 9}, {4, 25}};
        if(Sqr(n) != result) {
            throw runtime_error("Wrong map");
        }

    }

    {
        vector<map<int, pair<int, int>>> n = {
            {{2, {3, 4}}, {3, {4, 5}}}, {{4, {5, 6}}}
        }, result = {
            {{2, {9, 16}}, {3, {16, 25}}}, {{4, {25, 36}}}
        };
        if(Sqr(n) != result) {
            cout << "ALARM" << endl;
        }
    }

    return 0;
}
