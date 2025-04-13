#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int value) {
        data = value;
        next = prev = nullptr;
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

Node* flatten(Node* head)
{
    if(head == nullptr)
        return head;
    Node* curr = head;
    while(curr!=nullptr)
    {
        if(curr->child!=nullptr)
        {
            //flatten the child nodes
            Node* next = curr->next;
            curr->next = flatten(curr->child); //head of next layer
            curr->next->prev = curr;
            curr->child = nullptr;

            //find tail
            while(curr->next!=nullptr)
                curr= curr->next;

            //attach tail with next ptr
            if(next!=nullptr)
            {
                curr->next = next;
                next->prev = curr;
            }
        }
        curr = curr->next;
    }
    return head;
}

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
