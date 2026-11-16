#include <iostream>
#include <queue>
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

void BFS(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->name << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

int main() {
    Node* root = new Node("Electronics");
    root->left = new Node("Clothing");
    root->right = new Node("Mobiles");
    root->left->left = new Node("Men");
    root->left->right = new Node("Women");
    root->right->left = new Node("Laptops");
    root->right->right = new Node("Accessories");

    cout << "Breadth First Traversal: ";
    BFS(root);
    cout << endl;

    return 0;
}
