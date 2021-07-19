#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> result;
    auto it = find_if(elements.begin(), elements.end(), [&border](T elem) {
        return elem > border;
        }
    );
    for(auto i = it; i != elements.end();) {
        result.push_back(*(i++));
    }
    return result;
}

int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 10}, 5)) {
    cout << x << " ";
  }
  cout << endl;
  
  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}
