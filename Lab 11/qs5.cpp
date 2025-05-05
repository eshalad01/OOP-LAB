#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class StackUnderflowException : public runtime_error {
public:
    StackUnderflowException(const string& message)
        : runtime_error(message) {}
};

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    void push(const T& element) {
        elements.push_back(element);
    }

    void pop() {
        if (elements.empty()) {
            throw StackUnderflowException("Stack underflow: Cannot pop from an empty stack.");
        }
        elements.pop_back();
    }

    T top() const {
        if (elements.empty()) {
            throw StackUnderflowException("Stack underflow: Cannot access top of an empty stack.");
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }
};

int main() {
    Stack<int> stack;

    try {
        stack.push(1);
        stack.push(2);
        cout << "Top element: " << stack.top() << endl; 
        stack.pop();
        cout << "Top element after pop: " << stack.top() << endl; 
        stack.pop();
        stack.pop();
    } catch (const StackUnderflowException& e) {
        cout << "Exception caught: " << e.what() << endl;  
    }

    return 0;
}

