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
};

void runBstModule() {
    std::cout << "BST Demo" << std::endl;
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    tree.inorder();
}
