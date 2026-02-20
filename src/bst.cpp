#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insertRec(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->val) {
            node->left = insertRec(node->left, val);
        } else if (val > node->val) {
            node->right = insertRec(node->right, val);
        }
        return node;
    }

    void inorderRec(TreeNode* node) const {
        if (node != nullptr) {
            inorderRec(node->left);
            std::cout << node->val << " ";
            inorderRec(node->right);
        }
    }

    void cleanup(TreeNode* node) {
        if (node != nullptr) {
            cleanup(node->left);
            cleanup(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}
    
    ~BST() {
        cleanup(root);
    }

    void insert(int val) {
        root = insertRec(root, val);
    }

    void inorder() const {
        std::cout << "Inorder Traversal: ";
        inorderRec(root);
        std::cout << std::endl;
    }

    void menu() {
        int choice, value;

        do {
            std::cout << "\n--- BST Menu ---\n";
            std::cout << "1. Insert\n";
            std::cout << "2. Inorder Traversal\n";
            std::cout << "0. Back to Main Menu\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Enter value to insert: ";
                    std::cin >> value;
                    insert(value);
                    break;
                case 2:
                    inorder();
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

void runBstModule() {
    BST tree;
    tree.menu();
}
