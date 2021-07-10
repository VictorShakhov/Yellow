#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

void TestIncognito() {
    {
        Person p;
        AssertEqual(p.GetFullName(1), "Incognito", "Incognito check");
    }
}

void TestUnknownFirstName() {
    {
        Person p;
        p.ChangeLastName(1, "Shakhov");
        AssertEqual(p.GetFullName(2), "Shakhov with unknown first name", "Unknown first name");
    }
}

void TestUnknownLastName() {
    {
        Person p;
        p.ChangeFirstName(1, "Victor");
        AssertEqual(p.GetFullName(2), "Victor with unknown last name", "Unknown last name");
    }
}

void TestFullName() {
    {
        Person p;
        p.ChangeFirstName(1, "Victor");
        p.ChangeLastName(2, "Shakhov");
        AssertEqual(p.GetFullName(3), "Victor Shakhov", "Full name");
    }
}

void TestAll() {
    TestRunner tr;
    tr.RunTest(TestIncognito, "Incognito");
    tr.RunTest(TestUnknownFirstName, "Unknown first name");
    tr.RunTest(TestUnknownLastName, "Unknown last name");
    tr.RunTest(TestFullName, "Full name");
}

int main() {
    TestAll();
  // добавьте сюда свои тесты
  return 0;
}
