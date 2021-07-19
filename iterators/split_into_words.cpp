#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
string MakeWord(T& first_it, const T& last_it) {
    string word;
    while(first_it < last_it) {
        word.push_back(*first_it);
        ++first_it;
    }
    return word;
}

vector<string> SplitIntoWords(const string& s) {
    vector<string> words;
    auto first_it = s.begin();
    auto last_it = find_if(s.begin(), s.end(), [](char c) {return c == ' ';});
    while(first_it < s.end()) {
        words.push_back(MakeWord(first_it, last_it));
        first_it++;
        last_it = find_if(first_it, s.end(), [](char c) {return c == ' ';});
    }
    return words;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}