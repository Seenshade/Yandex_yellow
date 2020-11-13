#include<iostream>
#include <limits>

using namespace std;

int main(){
    double value = numeric_limits<double>::max() ;
    cout << "double min: " <<numeric_limits<double>::min() << endl;
    cout << "double max: " <<numeric_limits<double>::max() << endl;
    cout << value << endl;
    return 0;
}