#include <iostream>
#include "toolkit.h"
using namespace std;

class ArrayDS {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        cout << "Array resized to capacity " << capacity << ".\n";
    }

public:
    ArrayDS(int initialCapacity = 5) {
        size = 0;
        capacity = initialCapacity;
        arr = new int[capacity];
    }

    ~ArrayDS() {
        delete[] arr;
    }

    void insertElement(int value) {
        if (size >= capacity) {
            resize();
        }
        arr[size] = value;
        size++;
        cout << "Inserted " << value << " successfully.\n";
    }

    void deleteElement(int value) {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }

        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Element not found!\n";
            return;
        }

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
        cout << "Deleted " << value << " successfully.\n";
    }

    void searchElement(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << "Element found at index " << i << endl;
                return;
            }
        }
        cout << "Element not found!\n";
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }

        cout << "Array elements (Size: " << size << ", Capacity: " << capacity << "): ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void menu() {
        int choice, value;

        do {
            cout << "\n--- Dynamic Array Menu ---\n";
            cout << "1. Insert\n";
            cout << "2. Delete\n";
            cout << "3. Search\n";
            cout << "4. Display\n";
            cout << "0. Back to Main Menu\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    insertElement(value);
                    break;
                case 2:
                    cout << "Enter value to delete: ";
                    cin >> value;
                    deleteElement(value);
                    break;
                case 3:
                    cout << "Enter value to search: ";
                    cin >> value;
                    searchElement(value);
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

// This function will be used in main.cpp
void runArrayModule() {
    ArrayDS arr;
    arr.menu();
}