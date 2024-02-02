#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    // constructor
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class bTree {
    private:
        Node* root;

        // finds node w/ min key value in given subtree
        Node* findMin(Node* node) {
            Node* curr = node;
            while (curr && curr->left != nullptr) {
                curr = curr->left;
            }
            return curr;
        }
    public:
        bTree() : root(nullptr) {}

        // inserting element into tree
        Node* insert(Node* root, int value) {
            if(root == nullptr) {
                return new Node(value);
            }

            if(value < root->data) {
                root->left = insert(root->left, value);
            } else if (value > root->data) {
                root->right = insert(root->right, value);
            }
            return root;
        }

        // remove element from tree
        Node* remove(Node* root, int value) {
            if(root == nullptr) return root;

            if(value < root->data) {
                root->left = remove(root->left, value);
            } else if(value > root->data) {
                root->right = remove(root->right, value);
            } else {
                // one or no children
                if(root->left == nullptr) {
                    Node* tmp = root->right;
                    delete root;
                    return tmp;
                } else if (root->right == nullptr) {
                    Node* tmp = root->left;
                    delete root;
                    return tmp;
                }
            }

            // node has no children
            Node* tmp = findMin(root->right);
            root->data = tmp->data;
            root->right = remove(root->right, tmp->data);
        }

        // tree traversals! (3)

        // inorder traversal
        void inorder(Node* root) {
            if(root != nullptr) {
                inorder(root->left);
                cout << root->data << " ";
                inorder(root->right);
            }
        }
};

int main() {
    cout << "\nMain Function Started\n" << endl;
}