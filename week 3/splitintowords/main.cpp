#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s){
    vector<string> vs;
    auto str_iterator = begin(s);
    while(str_iterator != end(s)){
        string word;
        auto it_space = find_if(
            str_iterator, end(s),
            [](char symbol){
                 return symbol == ' ';
            }
        );
        while(str_iterator != it_space){
            word += *str_iterator;
            str_iterator++;
        }
        vs.push_back(word);
        if (it_space != end(s)){
            str_iterator++;
        }
    }
    return vs;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}