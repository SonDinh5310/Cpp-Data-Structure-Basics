#include <iostream>

using namespace std;

class node {
   public:
    int data;
    node* next;
    node(int value) {
        data = value;
        next = NULL;
    }
    node() {
        next = NULL;
    }
};

class SinglyLinkedList {
   public:
    node* head;
    SinglyLinkedList() {
        head = NULL;
    }
    void push(int d) {  //d is data
        node* newNode = new node(d);
        //* Kiem tra truong hop cay ko co node
        if (head == NULL) {
            head = newNode;
            return;
        }
        //* Gan gia tri head vao 1 bien temp
        node* temp = head;
        //* Cho temp chay den cuoi cung cua list
        while (temp->next != NULL) {
            temp = temp->next;
        }
        //* Gan temp->next bang gia tri moi
        temp->next = newNode;
    }

    int getVal(int pos) {
        if (head == NULL) {
            cout << "EMPTY";
            // return;
        }
        //* Gan gia tri head vao 1 bien temp
        node* temp = head;
        //* Cho temp chay den pos
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        //* Tra ve du lieu
        return temp->data;
    }
    void pop(int position) {
        //* Kiem tra truong hop cay ko co node
        if (head == NULL) {
            cout << "EMPTY";
            // return;
        }
        node* temp = head;

        //delete first node in list
        if (position == 0) {
            head = head->next;
            delete temp;
            return;
        }

        //find node before node need erase
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        node* temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
    }

    int getSize() {
        int count = 0;
        node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void print() {
        if (head == NULL) {
            cout << "EMPTY";
            // return;
        }
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    SinglyLinkedList myList;
    myList.push(10);
    myList.push(20);
    myList.push(30);
    myList.push(40);
    myList.push(50);
    myList.print();
    cout << "\n"
         << myList.getSize() << endl;
    cout << "\n"
         << myList.getVal(1) << endl;
    myList.pop(0);
    myList.print();
    return 0;
}
