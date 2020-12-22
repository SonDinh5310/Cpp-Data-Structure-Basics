#include <iostream>

using namespace std;

class Node {
   public:
    int key;
    int data;
    Node* left;
    Node* right;
    Node(int k, int d) {
        key = k;
        data = d;
        left = right = NULL;
    }
    Node() {
        left = right = NULL;
    }
};
class BST {
   private:
    Node* root;
    Node* Insert(Node* x, int k, int d) {
        if (x == NULL) {
            return new Node(k, d);
        }
        if (k > x->key) {
            x->right = Insert(x->right, k, d);
        } else if (k < x->key) {
            x->left = Insert(x->left, k, d);
        } else {
            x->data = d;
        }
        return x;
    }
    void inOrder(Node* x) {
        if (x == NULL) {
            return;
        }
        inOrder(x->left);
        cout << x->data << ' ';
        inOrder(x->right);
    }

    int getHeight(Node* root) {
        if (root == NULL) {
            return -1;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }

    Node* findPos(Node* root, int k) {
        if (root == NULL) {
            return root;
        }
        root->left = findPos(root->left, k);
        root->right = findPos(root->right, k);
    }

    Node* delete_node(Node* x, int key) {
        if (x == NULL) {
            return x;
        }
        if (key > x->key) {
            x->right = delete_node(x->right, key);
        } else {
            if (key < x->key) {
                x->left = delete_node(x->left, key);
            } else {
                //* Delete node with no child
                if (x->left == NULL && x->right == NULL) {
                    Node* temp = x;
                    x = NULL;
                    delete temp;
                    return x;
                }
                //* Delete node with 1 child
                if (x->left == NULL || x->right == NULL) {
                    Node* temp = x;
                    if (x->left != NULL) {
                        x = x->left;
                    } else {
                        x = x->right;
                    }
                    delete temp;
                    return x;
                }
                //* Delete node with 2 childs
                if (x->left != NULL && x->right != NULL) {
                    Node* temp = x;
                    temp = temp->right;

                    while (temp->left != NULL) {
                        temp = temp->left;
                    }
                    x->left = temp->left;
                    x->right = temp->right;
                    int k = temp->key;
                    x->right = delete_node(x->right, k);
                }
            }
        }
    }

   public:
    BST() {
        root = NULL;
    }
    void Insert(int k, int d) {
        root = Insert(root, k, d);
    }
    void inOrder() {
        inOrder(root);
    }
    int getHeight() {
        int height = getHeight(root);
    }
    void findPos(int k) {
        cout << findPos(root, k)->data;
    }
    void delete_node(int k) {
        root = delete_node(root, k);
    }
};
int main() {
    BST bst;
    bst.Insert(2, 20);
    bst.Insert(1, 10);
    bst.Insert(3, 30);
    bst.Insert(4, 50);
    bst.Insert(5, 60);
    bst.delete_node(4);
    bst.inOrder();

    // cout << bst.getHeight() << endl;
    return 0;
}
