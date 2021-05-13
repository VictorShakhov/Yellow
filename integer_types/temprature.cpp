#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t N;
    cin >> N;
    int64_t sum = 0;
    int avg_temp;
    vector<int> temp(N);
    vector<size_t> indexes;
    for(int& i : temp) {
        cin >> i;
        sum += i;
    }
    avg_temp = sum / static_cast<int>(N);
    for(size_t i = 0; i < N; ++i) {
        if(temp[i] > avg_temp) {
            indexes.push_back(i);
        }
    }
    cout << indexes.size() << endl;
    for(size_t i = 0; i < indexes.size(); ++i) {
        cout << indexes[i];
        if(i + 1 != indexes.size()) {
            cout << " ";
        }
    }
    return 0;
}

