#include <iostream>
#include <deque>

using namespace std;

class Operation{
public:
    Operation() {};
    Operation(const char& operation, const int& value){
        _operation = operation;
        _value = value;
    }
    char GetOperation() const {
        return _operation;
    }
    int GetValue() const {
        return _value;
    }
private:
    char _operation;
    int _value;
};

bool operator > (const Operation& lhs, const Operation& rhs){
    if ((lhs.GetOperation() == '*' || lhs.GetOperation() == '/') && (rhs.GetOperation() == '+' || rhs.GetOperation() == '-')){
        return true;
    }
    return false;
}

istream& operator>>(istream& input, Operation& operation){
    char input_operation;
    int input_value;
    cin >> input_operation >> input_value;
    operation = {input_operation, input_value};
    return input;
}



int main(int argc, char** argv){
    deque<string> expression;
    deque<Operation> operations;
    int first_value, operations_quantity;
    cin >> first_value >> operations_quantity;
    if (operations_quantity > 0){
        expression.push_back(to_string(first_value));
        for (int i = 0; i < operations_quantity; i++){
            Operation op;
            cin >> op;
            operations.push_back(op);
        }
    } else {
        cout << to_string(first_value);
    }
    for (auto it = begin(operations); it != end(operations); it++){
        expression.push_back(" " + string(1, (*it).GetOperation()) + " " + to_string((*it).GetValue()));
        if (it != end(operations) && *(it+1) > *it){
            expression.push_front("(");
            expression.push_back(")");
        }
    }
    for(auto it = begin(expression); it != end(expression);it++){
        cout << *it; 
    }
    return 0;
}