#include <iostream>
#include <vector>
#include "toolkit.h"
#include <stdexcept>
using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    void push(int val) {
        elements.push_back(val);
    }

    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    int top() const {
        if (!isEmpty()) {
            return elements.back();
        }
        throw runtime_error("Stack is empty");
    }

    bool isEmpty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }

    int capacity() const {
        return elements.capacity();
    }

    void display() const {
        cout << "Stack (Top to Bottom): ";
        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    void menu() {
        int choice, value;

        do {
            cout << "\n--- Stack Menu ---\n";
            cout << "1. Push\n";
            cout << "2. Pop\n";
            cout << "3. Top\n";
            cout << "4. Display\n";
            cout << "5. Size\n";
            cout << "6. Capacity\n";
            cout << "0. Back to Main Menu\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value to push: ";
                    cin >> value;
                    push(value);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    try {
                        cout << "Top: " << top() << endl;
                    } catch (const runtime_error& e) {
                        cout << e.what() << endl;
                    }
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    cout << "Size: " << size() << endl;
                    break;
                case 6:
                    cout << "Capacity: " << capacity() << endl;
                    break;
                case 0:
                    cout << "Returning to main menu...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 0);
    }
};

void runStackModule() {
    Stack s;
    s.menu();
}
