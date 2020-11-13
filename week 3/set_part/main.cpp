#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border){
    std::vector<T> new_v;
    auto it_border = std::find_if(
        begin(elements), end(elements),
        [&border](auto element){
            return element > border;
        }
    );
    // if (it_border != end(elements)){
    //     it_border++;
    // }
    while(it_border != end(elements)){
        new_v.push_back(*it_border++);
    }
    sort(begin(new_v), end(new_v));
    return new_v;
}

int main(int argc, char** argv){
    for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    std::string to_find = "Python";
    std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
    return 0;
}