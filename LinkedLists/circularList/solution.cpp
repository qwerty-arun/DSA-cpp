#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class CircularList {
    Node* head;
    Node* tail;
public:

    CircularList() : head(nullptr), tail(nullptr) {}

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead() {
        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        temp->next = nullptr;
        delete temp;
    }

    void deleteAtTail() {
        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = tail;
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        tail = prev;
        tail->next = head;
        temp->next = nullptr;
        delete temp;
    }

    void print() {
        if (head == nullptr) {
            return;
        }
        std::cout << head->data;
        Node* temp = head->next;
        while (temp != head) {
            std::cout << " -> " << temp->data;
            temp = temp->next;
        }
        std::cout << " (circular)" << std::endl;
    }
};

int main() {
    CircularList cll;
    cll.insertAtHead(1);
    cll.print();
    cll.insertAtHead(2);
    cll.print();
    cll.insertAtTail(3);
    cll.print();
    cll.insertAtTail(4);
    cll.print();

    cll.deleteAtHead();
    cll.print();
    cll.deleteAtTail();
    cll.print();
    cll.deleteAtHead();
    cll.print();
    cll.deleteAtTail();
    cll.print();

    return 0;
}
