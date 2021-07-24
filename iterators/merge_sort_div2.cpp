#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if(range_end - range_begin > 1) {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);
        auto border = elements.begin();
        advance(border, (range_end - range_begin) / 2);
        MergeSort(elements.begin(), border);
        MergeSort(border, elements.end());
        merge(elements.begin(), border, border, elements.end(), range_begin);
    }
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(v.begin(), v.end());
    for(auto i : v) {
        cout << i << " ";
    }
    return 0;
}
