#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int input;
    vector<int> numbers;
    cin >> input;
    while(input != 0){
        numbers.push_back(input--);
    }
    do
    {
        for (const auto& number: numbers){
            cout << number << " ";
        }
        cout << endl;
    } while (prev_permutation(begin(numbers), end(numbers)));
    
    return 0;
}