#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

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
    auto it_middle_first = begin(elements) + distance(begin(elements), end(elements)) / 3;
    auto it_middle_second = begin(elements) + 2*distance(begin(elements), end(elements)) / 3;
    // 4
    MergeSort(begin(elements), it_middle_first);
    MergeSort(it_middle_first, it_middle_second);
    MergeSort(it_middle_second, end(elements));
    // 5
    vector<typename RandomIt::value_type> tmp_elements;
    merge(begin(elements), it_middle_first, it_middle_first, it_middle_second, back_inserter(tmp_elements));
    // 6
    merge(begin(tmp_elements), end(tmp_elements), it_middle_second, end(elements), range_begin);
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