#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string& input_name) : Name(input_name) {
    }
    const string Name;
};


class Dog : public Animal{
public:
    Dog (const string& input_name) : Animal(input_name) {

    }
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main(int argc, char** argv){
    Dog dog("Dogie");
    dog.Bark();
    cout << dog.Name << " was bark!" << endl;
    return 0;
}