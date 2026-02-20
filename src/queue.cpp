#include <iostream>
#include <deque>
#include "toolkit.h"
#include <stdexcept>
using namespace std;

class Queue {
private:
    deque<int> elements;

public:
    void enqueue(int val) {
        elements.push_back(val);
    }

    void dequeue() {
        if (!isEmpty()) {
            elements.pop_front();
        } else {
            cout << "Queue Underflow" << endl;
        }
    }

    int front() const {
        if (!isEmpty()) {
            return elements.front();
        }
        throw runtime_error("Queue is empty");
    }

    bool isEmpty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }

    void display() const {
        cout << "Queue (Front to Back): ";
        for (const auto& el : elements) {
            cout << el << " ";
        }
        cout << endl;
    }

    void menu() {
        int choice, value;

        do {
            cout << "\n--- Queue Menu ---\n";
            cout << "1. Enqueue\n";
            cout << "2. Dequeue\n";
            cout << "3. Front\n";
            cout << "4. Display\n";
            cout << "5. Size\n";
            cout << "0. Back to Main Menu\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    enqueue(value);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    try {
                        cout << "Front: " << front() << endl;
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
                case 0:
                    cout << "Returning to main menu...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 0);
    }
};

void runQueueModule() {
    Queue q;
    q.menu();
}
