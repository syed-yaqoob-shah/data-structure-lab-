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

    Node* insertNode(Node* node, int value, bool& inserted) {
        if (node == NULL) {
            inserted = true;
            return new Node(value);
        }
        if (value < node->id) node->left = insertNode(node->left, value, inserted);
        else if (value > node->id) node->right = insertNode(node->right, value, inserted);
        return node; // Equal IDs are not inserted.
    }

    bool searchNode(Node* node, int value) const {
        if (node == NULL) return false;
        if (node->id == value) return true;
        if (value < node->id) return searchNode(node->left, value);
        return searchNode(node->right, value);
    }

    Node* minimum(Node* node) {
        while (node != NULL && node->left != NULL) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value, bool& found) {
        if (node == NULL) return NULL;
        if (value < node->id) node->left = deleteNode(node->left, value, found);
        else if (value > node->id) node->right = deleteNode(node->right, value, found);
        else {
            found = true;
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

    void insert(int value) {
        bool inserted = false;
        root = insertNode(root, value, inserted);
        if (inserted) cout << "Product ID inserted.\n";
        else cout << "Duplicate product ID. Not inserted.\n";
    }
    void search(int value) const {
        if (searchNode(root, value)) cout << "Product ID found.\n";
        else cout << "Product ID not found.\n";
    }
    void remove(int value) {
        bool found = false;
        root = deleteNode(root, value, found);
        if (found) cout << "Product ID deleted.\n";
        else cout << "Product ID not found; nothing deleted.\n";
    }
    void displayInorder() const { cout << "In-order: "; inorder(root); cout << "\n"; }
    void displayPreorder() const { cout << "Pre-order: "; preorder(root); cout << "\n"; }
    void displayPostorder() const { cout << "Post-order: "; postorder(root); cout << "\n"; }
};

int main() {
    BST inventory;
    int choice, id;

    do {
        cout << "\n===== ONLINE STORE INVENTORY =====\n";
        cout << "1. Insert a product ID\n";
        cout << "2. Search for a product ID\n";
        cout << "3. Delete a product ID\n";
        cout << "4. Display in-order traversal\n";
        cout << "5. Display pre-order traversal\n";
        cout << "6. Display post-order traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter product ID: ";
                cin >> id;
                inventory.insert(id);
                break;
            case 2:
                cout << "Enter product ID to search: ";
                cin >> id;
                inventory.search(id);
                break;
            case 3:
                cout << "Enter product ID to delete: ";
                cin >> id;
                inventory.remove(id);
                break;
            case 4: inventory.displayInorder(); break;
            case 5: inventory.displayPreorder(); break;
            case 6: inventory.displayPostorder(); break;
            case 7: cout << "Program ended.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
