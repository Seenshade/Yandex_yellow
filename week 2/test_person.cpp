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

class Person {
public:

  void ChangeFirstName(int year, const string& first_name) {
  }
  void ChangeLastName(int year, const string& last_name) {
  }
  string GetFullName(int year) {
  }
};

void TestFirstName(){
    Person person;
    person.ChangeFirstName(1487, "Gena");
    AssertEqual(person.GetFullName(1489), "Gena with unknown last name");
    person.ChangeFirstName(1480, "Gennady");
    AssertEqual(person.GetFullName(1485), "Gennady with unknown last name", "test for early name without last name");
    AssertEqual(person.GetFullName(1488), "Gena with unknown last name", "test for early name without last name");
}
void TestIncognito(){
    Person person;
    person.ChangeFirstName(1487, "Gena");
    AssertEqual(person.GetFullName(1485), "Incognito", "test for incognito in 1480");
    person.ChangeFirstName(1480, "Gennady");
    AssertEqual(person.GetFullName(1485), "Gennady with unknown last name", "test for wrong incognito");
}

void TestLastName(){
    Person person;
    person.ChangeLastName(1487, "Petrov");
    AssertEqual(person.GetFullName(1489), "Petrov with unknown first name", "test for last name");
    person.ChangeLastName(1480, "Petrenko");
    AssertEqual(person.GetFullName(1485), "Petrenko with unknown first name", "test for second last name");
}

void TestBothName(){
    Person person;
    person.ChangeFirstName(1487, "Gena");
    person.ChangeLastName(1485, "Petrov");
    AssertEqual(person.GetFullName(1489), "Gena Petrov", "test for both name");
    person.ChangeLastName(1488, "Petrenko");
    AssertEqual(person.GetFullName(1489), "Gena Petrenko", "test for both names, second last name");
    person.ChangeFirstName(1483, "Gennady");
    AssertEqual(person.GetFullName(1486), "Gennady Petrov");
}

void TestAll(){
    TestFirstName();
    TestIncognito();
    TestLastName();
}
int main() {
  TestRunner runner;
  runner.RunTest(TestAll, "TestAll");
  return 0;
}