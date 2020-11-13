#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    // 1
    if (range_end - range_begin < 2){
        return;
    }
    // 2
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    // 3
    auto it_middle = begin(elements) + distance(begin(elements), end(elements)) / 2;
    // 4
    MergeSort(begin(elements), it_middle);
    MergeSort(it_middle, end(elements));
    // 5
    merge(begin(elements), it_middle, it_middle, end(elements), range_begin);
}

int main(int argc, char** argv){
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}