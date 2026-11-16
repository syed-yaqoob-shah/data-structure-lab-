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

void display(Node* root) {
    if (root == NULL)
        return;

    cout << "Member: " << root->name << endl;

    cout << "Left Child: ";
    if (root->left != NULL)
        cout << root->left->name;
    else
        cout << "None";

    cout << endl;

    cout << "Right Child: ";
    if (root->right != NULL)
        cout << root->right->name;
    else
        cout << "None";

    cout << "\n\n";

    display(root->left);
    display(root->right);
}

int main() {
    Node* root = new Node("HOD");
    root->left = new Node("Coordinator CS");
    root->right = new Node("Coordinator AI");
    root->left->left = new Node("Faculty Member 1");
    root->left->right = new Node("Faculty Member 2");
    root->right->left = new Node("Faculty Member 3");
    root->right->right = new Node("Faculty Member 4");

    display(root);

    return 0;
}
