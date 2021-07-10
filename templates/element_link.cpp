#include <iostream>
#include <map>

using namespace std;

template<typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, const Key& k) {
    if(m.find(k) == m.end()) {
        throw runtime_error("Error");
    }
    return m[k];
}

int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl;
    return 0;
}
