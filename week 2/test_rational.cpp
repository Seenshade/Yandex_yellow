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

class Rational {
public:

  Rational();
  Rational(int numerator, int denominator) {
  }

  int Numerator() const {
  }

  int Denominator() const {
  }
};

void TestConstructor(){
    Rational r;
    AssertEqual(to_string(r.Numerator()) + "/" + to_string(r.Denominator()), "0/1", "Zero numerator & denominator 1");
    Rational r2(0,10);
    AssertEqual(to_string(r2.Numerator()) + "/" + to_string(r2.Denominator()), "0/1", "Zero numerator & denominator 1");
}

void TestReduction(){
    Rational r(4,6);
    AssertEqual(to_string(r.Numerator()) + "/" + to_string(r.Denominator()), "2/3", "reduction 4/6 to 2/3");
}

void TestNegative(){
    Rational r(2,-3);
    AssertEqual(to_string(r.Numerator()) + "/" + to_string(r.Denominator()), "-2/3", "numerator must be negative");
}

void TestZeroNumerator(){
    Rational r(2,3);
    AssertEqual(to_string(r.Numerator()) + "/" + to_string(r.Denominator()), "2/3", "both numbers must be positive");
    Rational r2(-2,-3);
    AssertEqual(to_string(r2.Numerator()) + "/" + to_string(r2.Denominator()), "2/3", "both numbers must be positive");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestConstructor, "Constructor test");
  runner.RunTest(TestReduction, "Reduction test");
  runner.RunTest(TestNegative, "Negative test");
  runner.RunTest(TestZeroNumerator, "Zero numerator test");
  return 0;
}