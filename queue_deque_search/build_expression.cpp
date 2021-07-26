#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    int x, n, a;
    char operation;
    cin >> x >> n;
    deque<string> expression;
    expression.push_back(to_string(x));
    for(int i = 0; i < n; ++i) {
        cin >> operation >> a;
        expression.push_front("(");
        expression.push_back(") " + string(1, operation) + " " + to_string(a));
    }
    for(auto i = expression.begin(); i < expression.end(); ++i) {
        cout << *i;
    }
    return 0;
}
