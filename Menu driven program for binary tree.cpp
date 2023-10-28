#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // Private helper functions
    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);
    Node* findMin(Node* node);
    void inOrderTraversal(Node* node);
    void preOrderTraversal(Node* node);
    void postOrderTraversal(Node* node);
    void display(Node* node, int level);

public:

    BinarySearchTree() : root(nullptr) {}
// Add a public method to access the tree height
int getHeight() {
    return findHeight(root);
}

    void insert(int value);
    void remove(int value);
    bool search(int value);
    void inOrder();
    void preOrder();
    void postOrder();
    int findHeight(Node* node);
    int findMin();
    int findMax();
    void displayTree();
};

Node* BinarySearchTree::insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }

    return node;
}

void BinarySearchTree::insert(int value) {
    root = insert(root, value);
}

Node* BinarySearchTree::remove(Node* node, int value) {
    if (node == nullptr) {
        return node;
    }

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }

    return node;
}

Node* BinarySearchTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void BinarySearchTree::remove(int value) {
    root = remove(root, value);
}

bool BinarySearchTree::search(int value) {
    Node* current = root;
    while (current != nullptr) {
        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

void BinarySearchTree::inOrderTraversal(Node* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

void BinarySearchTree::inOrder() {
    inOrderTraversal(root);
    cout << endl;
}

void BinarySearchTree::preOrderTraversal(Node* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

void BinarySearchTree::preOrder() {
    preOrderTraversal(root);
    cout << endl;
}

void BinarySearchTree::postOrderTraversal(Node* node) {
    if (node != nullptr) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }
}

void BinarySearchTree::postOrder() {
    postOrderTraversal(root);
    cout << endl;
}

int BinarySearchTree::findHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    return max(leftHeight, rightHeight) + 1;
}

int BinarySearchTree::findMin() {
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

int BinarySearchTree::findMax() {
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

void BinarySearchTree::display(Node* node, int level) {
    if (node != nullptr) {
        display(node->right, level + 1);
        cout << endl;
        if (node == root) {
            cout << "Root: ";
        }
        for (int i = 0; i < level && node != root; i++) {
            cout << "        ";
        }
        cout << node->data;
        display(node->left, level + 1);
    }
}

void BinarySearchTree::displayTree() {
    display(root, 0);
    cout << endl;
}

int main() {
    BinarySearchTree bst;
    int choice, value;
    bool found;

    do {
        cout << "Binary Search Tree Menu\n";
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Search\n";
        cout << "4. In-order Traversal\n";
        cout << "5. Pre-order Traversal\n";
        cout << "6. Post-order Traversal\n";
        cout << "7. Find Height\n";
        cout << "8. Find Minimum\n";
        cout << "9. Find Maximum\n";
        cout << "10. Display Tree\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Enter value to remove: ";
                cin >> value;
                bst.remove(value);
                break;
            case 3:
                cout << "Enter value to search for: ";
                cin >> value;
                found = bst.search(value);
                if (found) {
                    cout << "Value found in the tree.\n";
                } else {
                    cout << "Value not found in the tree.\n";
                }
                break;
            case 4:
                cout << "In-order Traversal: ";
                bst.inOrder();
                break;
            case 5:
                cout << "Pre-order Traversal: ";
                bst.preOrder();
                break;
            case 6:
                cout << "Post-order Traversal: ";
                bst.postOrder();
                break;
            case 7:
    cout << "Height of the tree: " << bst.getHeight() << endl;
    break;

            case 8:
                cout << "Minimum value: " << bst.findMin() << endl;
                break;
            case 9:
                cout << "Maximum value: " << bst.findMax() << endl;
                break;
            case 10:
                cout << "Binary Search Tree:\n";
                bst.displayTree();
                break;
            case 11:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 11);

    return 0;
}
