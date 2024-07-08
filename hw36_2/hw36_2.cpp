#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int precedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

vector<char> to_rpn(string expression) {
    stack<char> operator_stack;
    vector<char> output;

    for (char symbol : expression) {
        if (isalnum(symbol)) {
            output.push_back(symbol);
        }
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
            while (!operator_stack.empty() && precedence(operator_stack.top()) >= precedence(symbol)) {
                output.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.push(symbol);
        }
        else if (symbol == '(') {
            operator_stack.push('(');
        }
        else if (symbol == ')') {
            while (operator_stack.top() != '(') {
                output.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop(); // Pop the '('
        }
    }

    while (!operator_stack.empty()) {
        output.push_back(operator_stack.top());
        operator_stack.pop();
    }

    return output;
}

int main() {
    string expression = "1 + 2 * 3";
    vector<char> rpn = to_rpn(expression);

    cout << "Reversed polish writing: ";
    for (char c : rpn) {
        cout << c << " ";
    }
    cout << endl;


    return 0;
}
