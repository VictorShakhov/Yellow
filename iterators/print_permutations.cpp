#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

ostream& operator<<(ostream& os, vector<int> v) {
    bool first = true;
    for(auto i : v) {
        if(!first) {
            os << " ";
        }
        first = false;
        os << i;
    }
    return os;
}

void PrintPermutation(int n) {
    vector<int> v;
    for(int i = n; i > 0; --i) {
        v.push_back(i);
    }
    do
    {
        cout << v << endl;
    } while (prev_permutation(v.begin(), v.end()));
    
}

int main() {
    int n;
    cin >> n;
    PrintPermutation(n);
    return 0;
}
