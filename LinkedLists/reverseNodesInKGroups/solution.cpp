#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    void pushFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void printLinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void pushBack(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popFront() {
        if (head == nullptr) {
            std::cout << "Linked list is empty" << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void popBack() {
        if (head == nullptr) {
            std::cout << "Linked list is empty" << std::endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    void insert(int value, int position) {
        if (position < 0) {
            std::cout << "Invalid Position" << std::endl;
            return;
        }
        if (position == 0) {
            pushFront(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cout << "Invalid Position" << std::endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key) {
        Node* temp = head;
        int index = 0;
        while (temp != nullptr) {
            if (temp->data == key) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    Node* reverseKGrp(Node* head, int k) {
        Node* temp = head;
        int count = 0;

        // Check if there are at least k nodes
        while (count < k && temp != nullptr) {
            temp = temp->next;
            count++;
        }
        if (count < k) return head;

        // Reverse k nodes
        Node* prev = reverseKGrp(temp, k); // Recursive call
        temp = head;
        count = 0;
        while (count < k) {
            Node* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }
        return prev;
    }

    void reverseKGroup(int k) {
        head = reverseKGrp(head, k);
    }
};

int main() {
    List ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushBack(4);
    ll.pushBack(5);
    ll.pushBack(6);
    ll.pushBack(7);
    ll.pushBack(8);

    std::cout << "Original list:\n";
    ll.printLinkedList();

    ll.reverseKGroup(3);

    std::cout << "List after reversing in groups of 3:\n";
    ll.printLinkedList();

    return 0;
}

