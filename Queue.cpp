#include <iostream>

using namespace std;
class Node {
   public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
    Node() {
        next = NULL;
    }
};
class Queue {
    //! FIFO : first in first out
   private:
    Node* head;  //remove from here
    Node* tail;  //add here
   public:
    Queue() {
        head = tail = NULL;
    }
    bool isEmpty() {
        return (head == NULL);
    }

    int peek() {
        if (head == NULL)
            throw "Empty";  //const char* const char int float
        return head->data;
    }

    void add(int d) {
        //* Khai bao bien newNode kieu Node*, gan data = d
        Node* newNode = new Node(d);
        //* Kiem tra tail co != NULL
        if (tail != NULL) {
            //* Neu co, gan tail->next = gia tri newNode moi khoi tao
            tail->next = newNode;
            //* Update tail
            tail = tail->next;
        } else {
            //* Neu tail rong --> head cung rong --> queue rong --> gan head = tail = gia tri moi
            head = tail = newNode;
        }
    }
    void myRemove() {
        //* Kiem tra head
        if (head == NULL) {
            //* head rong --> tra ve "Empty" --> ket thuc chuong trinh
            cout << "Queue is empty" << endl;
            return;
        }
        //* Tao bien temp, gan temp = head
        Node* temp = head;
        //* Update head, cho head tro den head->next
        head = head->next;
        //* KT head (truong hop chi co 1 phan tu)
        if (head == NULL) {
            tail = NULL;
        }
        //* Xoa bien temp
        delete temp;
    }
    void printOut() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
    }
};
int main() {
    Queue q;
    q.add(10);
    q.add(20);
    q.add(30);
    q.add(40);
    q.printOut();
    q.myRemove();
    cout << "\n";
    q.printOut();
    cout << "\n";
    //    if(q.isEmpty())
    //        cout << "YES" << endl;
    //    else
    //        cout << "NO" << endl;
    try {
        int val = q.peek();
        cout << val << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}
