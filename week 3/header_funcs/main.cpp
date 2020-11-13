#include <iostream>
#include "sum_reverse_sort.h"

using namespace std;

ostream& operator <<(ostream& out, const vector<int> v){
    bool first = true;
    out << "[";
    for (const auto& item : v){
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
    cout << "Sum 2 and 3 is " << Sum(2,3) << endl;
    cout << "Reverse abcd is " << Reverse("abcd") << endl;
    vector<int> vi = {5,1,4,2,3};
    Sort(vi);
    cout << "Sort [5,1,4,2,3] is " << vi << endl;
    return 0;
}