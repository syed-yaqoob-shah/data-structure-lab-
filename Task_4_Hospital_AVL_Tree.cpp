#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->key)
        root->left = insert(root->left, value);
    else if (value > root->key)
        root->right = insert(root->right, value);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && value < root->left->key)
        return rightRotate(root);

    if (balance < -1 && value > root->right->key)
        return leftRotate(root);

    if (balance > 1 && value > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && value < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void displayTree(Node* root, int space = 0) {
    if (root == NULL)
        return;

    space += 5;
    displayTree(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->key << " (Height: " << root->height
         << ", Balance Factor: " << getBalance(root) << ")\n";

    displayTree(root->left, space);
}

int main() {
    Node* root = NULL;
    int values[] = {15, 25, 35, 45, 55, 65, 75};

    for (int i = 0; i < 7; i++)
        root = insert(root, values[i]);

    cout << "In-order Traversal: ";
    inorder(root);

    cout << "\n\nFinal Balanced AVL Tree:\n";
    displayTree(root);

    return 0;
}
