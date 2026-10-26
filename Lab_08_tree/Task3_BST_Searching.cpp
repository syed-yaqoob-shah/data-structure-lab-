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
        return node; // Duplicate IDs are ignored.
    }

public:
    BST() : root(NULL) {}
    ~BST() { clear(root); }

    void insert(int value) { root = insertNode(root, value); }

    void search(int target) const {
        Node* current = root;
        int comparisons = 0;
        while (current != NULL) {
            comparisons++;
            if (target == current->id) {
                cout << "Book Found\n";
                cout << "Comparisons made: " << comparisons << "\n";
                return;
            } else if (target < current->id) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        cout << "Book Not Found\n";
        cout << "Comparisons made: " << comparisons << "\n";
    }

private:
    void clear(Node* node) {
        if (node == NULL) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
};

int main() {
    BST library;
    int bookIDs[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) library.insert(bookIDs[i]);

    int searchID;
    cout << "Enter book ID to search: ";
    cin >> searchID;
    library.search(searchID);
    return 0;
}
