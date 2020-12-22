#include <iostream>

using namespace std;

bool RED = true;
bool BLACK = false;
class Node {
   public:
    int key;
    int data;
    Node* left;
    Node* right;
    bool color;
    Node(int k, int d, bool cl) {
        key = k;
        data = d;
        left = right = NULL;
        color = cl;
    }
};
class LLRB {
   private:
    Node* root;
    bool isRed(Node* x) {
        if (x == NULL)
            return BLACK;
        return x->color == RED;
    }
    int findKey(int k) {
        Node* x = root;
        while (x != NULL) {
            if (k > x->key)
                x = x->right;
            else if (k < x->key)
                x = x->left;
            else
                return x->data;
        }
        throw "NOT FOUND";
        return 0;
    }

    //elementary red-black BST operation to maintain invariant of 2-3 tree
    //check isRed(h->right) == RED
    Node* rotateLeft(Node* h) {
        Node* x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }
    //check isRed(h->right)
    //Note: left leaning
    Node* rotateRight(Node* h) {
        Node* x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = BLACK;
        return x;
    }
    //check !isRed(h)
    //       isRed(h->left)
    //       idRed(h->right)
    void flipColor(Node* h) {
        h->left->color = BLACK;
        h->right->color = BLACK;
        h->color = RED;
    }

    //insertion
    Node* put(Node* x, int key, int data) {
        if (x == NULL)
            return new Node(key, data, RED);
        if (key > x->key)
            x->right = put(x->right, key, data);
        else if (key < x->key)
            x->left = put(x->left, key, data);
        else
            x->data = data;

        if (isRed(x->right) && !isRed(x->left)) x = rotateLeft(x);       //lean left
        if (isRed(x->left) && isRed(x->left->left)) x = rotateRight(x);  //balance 4_nodes
        if (isRed(x->left) && isRed(x->right)) flipColor(x);             //split 4_nodes
        return x;
    }
    void printOut(Node* x) {
        if (x->left != NULL)
            printOut(x->left);
        cout << x->data << ' ';
        if (x->right != NULL)
            printOut(x->right);
    }
    Node* delete_node(Node* x, int key) {
        if (x == NULL)
            return x;
        if (key > x->key)
            x->right = delete_node(x->right, key);
        else if (key < x->key)
            x->left = delete_node(x->left, key);
        else {
            //delete node(is leaf) : setting parent link to NULL
            if (x->left == NULL && x->right == NULL) {
                delete x;
                x = NULL;
                return x;
            }
            //delete node(has 1 child) : replacing parent link
            if (x->left == NULL || x->right == NULL) {
                Node* temp = x;
                if (x->left == NULL)
                    x = x->right;
                else
                    x = x->left;
                delete temp;
            }
            //delete node(has 2 childs) :
            //find successor of x
            //replace key and data of x by successor
            //delete successor
            if (x->left != NULL && x->right != NULL) {
                Node* successor = x;
                successor = successor->right;
                while (successor->left != NULL) {
                    successor = successor->left;
                }
                x->key = successor->key;
                x->data = successor->data;
                int k = successor->key;
                successor = delete_node(successor, k);
            }
        }
        return x;
    }

   public:
    LLRB() {
        root = NULL;
    }
    int get(int k) {
        int value;
        try {
            value = findKey(k);
            return value;
        } catch (const char* msg) {
            cout << msg << endl;
        }
        return 1;
    }
    void put(int k, int d) {
        root = put(root, k, d);
    }
    void delete_node(int k) {
        root = delete_node(root, k);
    }
    void printOut() {
        printOut(root);
    }
};

int main() {
    LLRB tree;
    tree.put(1, 10);
    tree.put(2, 20);
    tree.put(3, 30);
    tree.put(0, 0);
    cout << tree.get(1) << endl;
    tree.delete_node(1);
    cout << tree.get(1);
    //tree.printOut();
    return 0;
}
