#pragma once

#include <set>
#include <map>
#include <string>


template <class T>
ostream& operator << (ostream& os, const set<T>& s);

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m);

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint);

inline void Assert(bool b, const string& hint);


