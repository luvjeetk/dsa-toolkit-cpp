#include <iostream>
using namespace std;
// Singly Linked List Node
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Destructor to clean up memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" <<endl;
    }

    void remove(int val) {
        if (head == nullptr) return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != val) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    bool search(int val) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == val) return true;
            current = current->next;
        }
        return false;
    }

    void menu() {
        int choice, value;

        do {
            cout << "\n--- Linked List Menu ---\n";
            cout << "1. Insert at End\n";
            cout << "2. Delete by Value\n";
            cout << "3. Search\n";
            cout << "4. Display\n";
            cout << "0. Back to Main Menu\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    insert(value);
                    break;
                case 2:
                    cout << "Enter value to delete: ";
                    cin >> value;
                    remove(value);
                    break;
                case 3:
                    cout << "Enter value to search: ";
                    cin >> value;
                    if (search(value)) {
                        cout << "Found\n";
                    } else {
                        cout << "Not found\n";
                    }
                    break;
                case 4:
                    display();
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

// Function used by main.cpp
void runLinkedListModule() {
    LinkedList list;
    list.menu();
}
