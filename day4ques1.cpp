#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }
    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack stack;
    stack.push(5);
    stack.push(2);
    stack.push(8);
    stack.push(17);
    stack.push(10);
    stack.push(18);
    stack.push(9);
    stack.push(11);
    stack.push(19);

    cout << "Minimum: " << stack.getMin() << endl;
    stack.pop();
    cout << "Minimum: " << stack.getMin() << endl;
    stack.pop();
    cout << "Top: " << stack.top() << endl;   
    cout << "Minimum: " << stack.getMin() << endl; 

    return 0;
}
