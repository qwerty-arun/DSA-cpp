#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor for the Node class [1]
    Node(int value) {
        data = value;
        next = prev = nullptr; // Initialising next pointer to null [2]
    }
};

class DoublyList {
private:
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    void pushFront(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode; 
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode; 
            head = newNode;
        }
    }
    void pushBack(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popFront() {
        if (head == nullptr) {
            std::cout << "Doubly LinkedList is empty" << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void popBack() {
        if (head == nullptr) {
            std::cout << "Doubly LinkedList is empty" << std::endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << (temp->next ? " <-> " : "");
            temp = temp->next;
        }
        std::cout << " <-> nullptr" << std::endl;
    }

};

int main() {
    DoublyList dll;
    dll.pushFront(1);
    dll.print();
    dll.pushFront(2);
    dll.print();
    dll.pushFront(3);
    dll.print();
    dll.pushBack(4);
    dll.print();
    dll.pushBack(5);
    dll.print();

    dll.popFront();
    dll.print();
    dll.popBack();
    dll.print();
    dll.popFront();
    dll.print();
    dll.popBack();
    dll.print();
    dll.popFront();
    dll.print();
    return 0;
}
