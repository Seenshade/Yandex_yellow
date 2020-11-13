#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

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

template<typename T>
int SolveLinearEquation(const T& b, const T& c){
    if (b == 0){
        return 0;
    }
    return 1;
}

template<typename T>
int SolveQuadraticEquation(const T& a, const T& b, const T& c){
    T discriminant = b*b - 4*a*c;
    if (discriminant > 0){
        return 2;
    } else if (discriminant == 0){
        return 1;
    } else {
        return 0;
    }
}

int GetDistinctRealRootCount(double a, double b, double c) {
    try
    {
        if (a == 0){
            return SolveLinearEquation(b, c);
        } else {
            return SolveQuadraticEquation(a, b, c);
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
}
void TestLinearEquation(){
    AssertEqual(GetDistinctRealRootCount(0, numeric_limits<double>::min(), numeric_limits<double>::max()), 1, "a = 0, b = double_min, c = double_max, double overflow");
    AssertEqual(GetDistinctRealRootCount(0,0,4), 0, "a = 0, b = 0, c = 4, division by zero");
}

void TestQuadraticEquation(){
    AssertEqual(GetDistinctRealRootCount(2,5,2), 2, "a = 2, b = 5, c = 2");
    AssertEqual(GetDistinctRealRootCount(1,4,3), 2, "a = 1, b = 4, c = 3");
    AssertEqual(GetDistinctRealRootCount(10,4,3), 0, "a = 10, b = 4, c = 3, discriminant is negative");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestLinearEquation, "Test linear equations");
  runner.RunTest(TestQuadraticEquation, "Test quadratic equations");
  return 0;
}