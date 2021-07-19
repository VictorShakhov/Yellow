#include <vector>
#include <iostream>


using namespace std;

void PrintVectorPart(vector<int> numbers) {
    if(!numbers.empty()) {
        auto it = numbers.begin();
        while(it < numbers.end() && *it >= 0) {
            it++;
        }
        it--;
        for(auto i = it; i >= numbers.begin(); --i) {
            if(i != it) {
                cout << " ";
            }
            cout << *i;
        }
    }
}

int main() {
    vector<int> numbers;
    size_t n;
    cin >> n;
    numbers.resize(n);
    for(auto i = numbers.begin(); i < numbers.end(); ++i) {
        cin >> *i;
    }
    PrintVectorPart(numbers);
    cout << endl;
    return 0;
}
