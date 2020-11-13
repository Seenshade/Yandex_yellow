#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

string GetStringByPrefix(const string& word, const string& prefix){
    string str = "";
    for(auto it = begin(word); it != begin(word) + prefix.length(); it++){
        str += *it; 
    }
    return str;
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
    auto lower_it = lower_bound(range_begin, range_end, prefix,
    [prefix](auto lhs, auto rhs) {return GetStringByPrefix(lhs, prefix) < rhs;});
    auto upper_it = upper_bound(range_begin, range_end, prefix,
    [prefix](auto lhs, auto rhs) {return GetStringByPrefix(rhs, prefix) > lhs;});
    return make_pair(lower_it, upper_it);
}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
    
    const auto mo_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    const auto mt_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
        (mt_result.second - begin(sorted_strings)) << endl;
    
    const auto na_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
        (na_result.second - begin(sorted_strings)) << endl;
    
  return 0;
    
  return 0;
}