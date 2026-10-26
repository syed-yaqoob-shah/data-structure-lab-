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

    Node* minimum(Node* node) {
        while (node != NULL && node->left != NULL) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value, bool& found) {
        if (node == NULL) return NULL;

        if (value < node->id) {
            node->left = deleteNode(node->left, value, found);
        } else if (value > node->id) {
            node->right = deleteNode(node->right, value, found);
        } else {
            found = true;
            // Case 1: no child (leaf)
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            // Case 2: one child
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: two children; replace with inorder successor
            Node* successor = minimum(node->right);
            node->id = successor->id;
            bool ignored = false;
            node->right = deleteNode(node->right, successor->id, ignored);
        }
        return node;
    }

    void inorder(Node* node) const {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
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

    void remove(int value) {
        bool found = false;
        root = deleteNode(root, value, found);
        if (found) cout << "Employee ID " << value << " deleted.\n";
        else cout << "Employee ID not found.\n";
    }

    void display() const {
        cout << "Remaining employee IDs in ascending order: ";
        inorder(root);
        cout << "\n";
    }
};

int main() {
    BST employees;
    int ids[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) employees.insert(ids[i]);

    cout << "Initial IDs: 20 30 40 50 60 70 80\n";
    cout << "Choose a test case:\n";
    cout << "1. Delete leaf node (20)\n";
    cout << "2. Delete node with one child (30 after deleting 20)\n";
    cout << "3. Delete node with two children (50)\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        employees.remove(20);
    } else if (choice == 2) {
        employees.remove(20); // Leaves node 30 with one child (40)
        employees.remove(30);
    } else if (choice == 3) {
        employees.remove(50);
    } else {
        cout << "Invalid choice.\n";
        return 0;
    }

    employees.display();
    return 0;
}
