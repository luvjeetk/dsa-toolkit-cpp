#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> elements;

public:
    void push(int val) {
        elements.push_back(val);
    }

    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        } else {
            std::cout << "Stack Underflow" << std::endl;
        }
    }

    int top() const {
        if (!isEmpty()) {
            return elements.back();
        }
        throw std::runtime_error("Stack is empty");
    }

    bool isEmpty() const {
        return elements.empty();
    }

    void display() const {
        std::cout << "Stack (Top to Bottom): ";
        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

void runStackModule() {
    std::cout << "Stack Demo" << std::endl;
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    std::cout << "Top: " << s.top() << std::endl;
    
    s.pop();
    std::cout << "After pop: ";
    s.display();
}
