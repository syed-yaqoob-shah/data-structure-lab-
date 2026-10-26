#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string personName) {
        name = personName;
        left = NULL;
        right = NULL;
    }
};

void displayTree(Node* root) {
    if (root == NULL) return;

    cout << "Person: " << root->name << "\n";
    cout << "  Left child: ";
    if (root->left != NULL) cout << root->left->name;
    else cout << "None";
    cout << "\n  Right child: ";
    if (root->right != NULL) cout << root->right->name;
    else cout << "None";
    cout << "\n\n";

    displayTree(root->left);
    displayTree(root->right);
}

void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
   
    Node* grandfather = new Node("Grandfather");
    grandfather->left = new Node("Father");
    grandfather->right = new Node("Uncle");
    grandfather->left->left = new Node("Child1");
    grandfather->left->right = new Node("Child2");
    grandfather->right->left = new Node("Cousin1");
    grandfather->right->right = new Node("Cousin2");

    cout << "FAMILY TREE INFORMATION\n\n";
    displayTree(grandfather);

    deleteTree(grandfather);
    return 0;
}
