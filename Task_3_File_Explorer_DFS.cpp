#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string value) {
        name = value;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->name << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->name << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->name << " ";
}

int main() {
    Node* root = new Node("C");
    root->left = new Node("Documents");
    root->right = new Node("Pictures");
    root->left->left = new Node("Assignments");
    root->left->right = new Node("Notes");
    root->right->left = new Node("Family");
    root->right->right = new Node("Screenshots");

    cout << "In-order: ";
    inorder(root);

    cout << "\nPre-order: ";
    preorder(root);

    cout << "\nPost-order: ";
    postorder(root);

    cout << endl;

    return 0;
}
