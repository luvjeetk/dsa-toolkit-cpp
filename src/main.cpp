#include <iostream>
#include "toolkit.h"
using namespace std;

void showMainMenu() {
    cout << "\n====== DSA TOOLKIT ======\n";
    cout << "1. Array\n";
    cout << "2. Linked List\n";
    cout << "3. Stack\n";
    cout << "4. Queue\n";
    cout << "5. Binary Search Tree\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;

    do {
        showMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                runArrayModule();
                break;
            case 2:
                runLinkedListModule();
                break;
            case 3:
                runStackModule();
                break;
            case 4:
                runQueueModule();
                break;
            case 5:
                runBstModule();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
