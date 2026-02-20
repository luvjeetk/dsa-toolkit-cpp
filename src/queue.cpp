#include <iostream>
#include <deque>

class Queue {
private:
    std::deque<int> elements;

public:
    void enqueue(int val) {
        elements.push_back(val);
    }

    void dequeue() {
        if (!isEmpty()) {
            elements.pop_front();
        } else {
            std::cout << "Queue Underflow" << std::endl;
        }
    }

    int front() const {
        if (!isEmpty()) {
            return elements.front();
        }
        throw std::runtime_error("Queue is empty");
    }

    bool isEmpty() const {
        return elements.empty();
    }

    void display() const {
        std::cout << "Queue (Front to Back): ";
        for (const auto& el : elements) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
};

void runQueueModule() {
    std::cout << "Queue Demo" << std::endl;
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    std::cout << "Front: " << q.front() << std::endl;

    q.dequeue();
    std::cout << "After dequeue: ";
    q.display();
}
