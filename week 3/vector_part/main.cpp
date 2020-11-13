#include <iostream>
#include <vector>
#include <algorithm>

void PrintVectorPart(const std::vector<int>& numbers){
    auto number_iterator = std::find_if(
        begin(numbers), end(numbers),
        [](const int& item){
            return item < 0;
        }
    );
    bool first = true;
    while(number_iterator != begin(numbers)){
        --number_iterator;
        if (!first){
            std::cout << " ";
        }
        first = false;
        std::cout << *number_iterator;
    }
}

int main(int argc, char** argv){
    PrintVectorPart({6, 1, 8, -5, 4});
    std::cout << std::endl;
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    std::cout << std::endl;
    PrintVectorPart({6, 1, 8, 5, 4});
    std::cout << std::endl;   
    return 0;
}