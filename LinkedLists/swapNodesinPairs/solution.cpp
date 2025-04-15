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
            std::cout << "Linklist is empty" << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    void popBack() {
        if (head == nullptr) {
            std::cout << "Linklist is empty" << std::endl;
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

    void swapPairs()
    {
        if(head == nullptr && head->next==nullptr)
            return ;

        Node* first = head;
        Node* sec= head ->next; 
        Node* prev = nullptr;
        while(first!=nullptr && sec!=nullptr)
        {
            //Swapping
            Node* third = sec->next;
            sec->next = first;
            first->next = third;

            //Valid prev pointer
            if(prev!=nullptr)
                prev->next = sec;
            else
                head = sec;

            //Updating for next iteration
            prev = first;
            first = third;

            //To check if third pointer is valid 
            if(third!=nullptr)
                sec = third->next;
            else
                sec = nullptr;
        }
    }
};

int main() {
    List ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushFront(4);
    ll.pushFront(5);
    ll.printLinkedList();
    ll.swapPairs();
    ll.printLinkedList();
    return 0;
}
