#include <iostream>
#include <vector>

using namespace std;

class Node {
   public:
    int data;
    Node* prev;
    Node(int d) {
        data = d;
        prev = NULL;
    }
    Node() {
        prev = NULL;
    }
};

class Stack {
    //! FILO : first in last out
   private:
    Node* head;

   public:
    Stack() {
        head = NULL;
    }

    bool isEmpty() {
        return (head == NULL);
    }

    //* Tra ve gia tri head cua stack
    int top() {
        if (isEmpty()) {
            throw "Empty";
        }
        return head->data;
    }

    void push(int d) {
        //* Khoi tao newNode, gan data = d
        Node* newNode = new Node(d);
        if (isEmpty()) {  // Day la truong hop rong
                          //* Neu rong thi gan head = newNode luon roi ket thuc
            head = newNode;
            return;
        }
        //* Neu khong, moc noi newNode voi head bang cach gan
        newNode->prev = head;
        //* Tro head den gia tri moi dua vao
        head = newNode;
    }

    void print() {
        //* Khai bien
        Node* temp = head;
        vector<int> result;

        while (temp != NULL) {
            //* Day temp->data vao result
            result.push_back(temp->data);
            //* tro temp ve truoc
            temp = temp->prev;
        }
        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i] << " ";
        }
    }

    void pop() {  //* Ham xoa phan tu o dau stack
        if (isEmpty()) {
            cout << "Empty" << endl;
            return;
        }
        //* Gan delNode = head
        Node* delNode = head;
        //* tro head ve sau, head = head->prev
        head = head->prev;
        //* Xoa delNode
        delete delNode;
    }

    // void printOut() {
    //     if (isEmpty()) {
    //         return;
    //     }
    //     printOut(head);
    //     cout << head->data << " ";
    // }
};

int main() {
    Stack s;
    if (s.isEmpty()) {
        cout << "empty" << endl;
    }
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    if (s.isEmpty()) {
        cout << "empty" << endl;
    } else {
        cout << "not empty" << endl;
    }
    cout << s.top() << endl;
    s.pop();
    s.print();

    return 0;
}
