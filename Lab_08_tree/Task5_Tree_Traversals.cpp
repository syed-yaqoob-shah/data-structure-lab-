#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int id;
        Node* left;
        Node* right;
        Node(int value) : id(value), left(NULL), right(NULL) {}
    };
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == NULL) return new Node(value);
        if (value < node->id) node->left = insertNode(node->left, value);
        else if (value > node->id) node->right = insertNode(node->right, value);
        return node;
    }

    void inorder(Node* node) const {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
    }
    void preorder(Node* node) const {
        if (node == NULL) return;
        cout << node->id << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node* node) const {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->id << " ";
    }
    void clear(Node* node) {
        if (node == NULL) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BST() : root(NULL) {}
    ~BST() { clear(root); }
    void insert(int value) { root = insertNode(root, value); }
    void displayTraversals() const {
        cout << "In-order (Left, Root, Right): ";
        inorder(root);
        cout << "\nPre-order (Root, Left, Right): ";
        preorder(root);
        cout << "\nPost-order (Left, Right, Root): ";
        postorder(root);
        cout << "\nIn-order traversal displays IDs in ascending order.\n";
    }
};

int main() {
    BST patients;
    int ids[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) patients.insert(ids[i]);
    patients.displayTraversals();
    return 0;
}
