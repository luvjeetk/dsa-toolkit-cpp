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

    void menu() {
        int choice, value;

        do {
            std::cout << "\n--- Stack Menu ---\n";
            std::cout << "1. Push\n";
            std::cout << "2. Pop\n";
            std::cout << "3. Top\n";
            std::cout << "4. Display\n";
            std::cout << "0. Back to Main Menu\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Enter value to push: ";
                    std::cin >> value;
                    push(value);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    std::cout << "Top: " << top() << std::endl;
                    break;
                case 4:
                    display();
                    break;
                case 0:
                    std::cout << "Returning to main menu...\n";
                    break;
                default:
                    std::cout << "Invalid choice!\n";
            }
        } while (choice != 0);
    }
};

void runStackModule() {
    Stack s;
    s.menu();
}
