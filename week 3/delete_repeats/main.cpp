#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements){
    set<T> unique_elements;
    copy(begin(elements), end(elements), inserter(unique_elements, begin(unique_elements)));
    elements.clear();
    copy(begin(unique_elements), end(unique_elements), back_inserter(elements));
}

int main(int argc, char** argv){
    vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
    RemoveDuplicates(v1);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;
    
    vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
    RemoveDuplicates(v2);
    for (const string& s : v2) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}