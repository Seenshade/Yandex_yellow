#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool f(const int& v){
    if (v > 5){
        return true;
    }
    return false;
}

template<class T>
ostream& operator<< (ostream& out, const vector<T> v){
    bool first = true;
    out << "[";
    for(const auto& item : v){
        if (!first){
            out << ",";
        }
        first = false;
        out << item;
    }
    out << "]";
    return out;
}
 
int main(){
    vector<int> vi = {5, 10, 7, 1, 3, 6, 2};
    sort(begin(vi), end(vi));
    cout << vi << endl;
    sort(begin(vi), end(vi),
    [](int lhs, int rhs){ return f(lhs) > f(rhs); });
    cout << vi << endl;
    auto it = partition_point(begin(vi), end(vi), f);
    vi.erase(it, end(vi));
    cout << vi << endl;
    return 0;
}