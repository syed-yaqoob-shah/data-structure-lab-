#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int roll;
        Node* left;
        Node* right;
        Node(int value) : roll(value), left(NULL), right(NULL) {}
    };
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == NULL) return new Node(value);
        if (value < node->roll)
            node->left = insertNode(node->left, value);
        else if (value > node->roll)
            node->right = insertNode(node->right, value);
        else
            cout << "Duplicate roll number ignored: " << value << "\n";
        return node;
    }

    void inorder(Node* node) const {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->roll << " ";
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
    void displayAscending() const {
        cout << "Roll numbers in ascending order: ";
        inorder(root);
        cout << "\n";
    }
};

int main() {
    BST students;
    int roll1, roll2;

    int initialRolls[] = {45, 25, 65, 15, 35, 55, 75};
    for (int i = 0; i < 7; i++) students.insert(initialRolls[i]);

    cout << "Enter first additional roll number: ";
    cin >> roll1;
    cout << "Enter second additional roll number: ";
    cin >> roll2;

    students.insert(roll1);
    students.insert(roll2);
    students.displayAscending();
    return 0;
}
