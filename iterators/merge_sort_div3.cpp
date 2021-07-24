#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if(range_end - range_begin > 1) {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);
        vector<typename RandomIt::value_type> dummy;
        auto border1 = elements.begin();
        advance(border1, (range_end - range_begin) / 3);
        auto border2 = border1;
        advance(border2, (range_end - range_begin) / 3);
        MergeSort(elements.begin(), border1);
        MergeSort(border1, border2);
        MergeSort(border2, elements.end());
        merge(elements.begin(), border1, border1, border2, back_inserter(dummy));
        merge(dummy.begin(), dummy.end(), border2, elements.end(), range_begin);
    }
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 3};
    MergeSort(v.begin(), v.end());
    for(auto i : v) {
        cout << i << " ";
    }
    return 0;
}
