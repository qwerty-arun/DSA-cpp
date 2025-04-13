#include <iostream>

class Node {
public:
    int data;
    Node* next;

    // Constructor for the Node class [1]
    Node(int value) {
        data = value;
        next = nullptr; // Initialising next pointer to null [2]
    }
};

class List {
private:
    Node* head; // Head pointer to the first node [2, 3]
    Node* tail; // Tail pointer to the last node (optional but used in some operations) [2, 3]

public:
    // Constructor for the List class [2]
    List() {
        head = nullptr; // Initially, an empty list has a null head [4]
        tail = nullptr; // Initially, an empty list has a null tail [4]
    }

    // Function to add a new node at the beginning of the linked list (push front) [4, 5]
    void pushFront(int value) {
        // Create a new node [5]
        Node* newNode = new Node(value); // Using the constructor of the Node class [5]

        // Case 1: If the linked list is empty [4, 5]
        if (head == nullptr) {
            head = newNode; // The new node becomes the head [5]
            tail = newNode; // The new node also becomes the tail [5]
        }
        // Case 2: If the linked list is not empty [6]
        else {
            newNode->next = head; // The next pointer of the new node points to the current head [7]
            head = newNode; // The new node becomes the new head [7]
        }
    }

    // Function to add a new node at the end of the linked list (push back) [4, 8]
    void pushBack(int value) {
        // Create a new node [8]
        Node* newNode = new Node(value);

        // Case 1: If the linked list is empty [8]
        if (head == nullptr) {
            head = newNode; // The new node becomes the head [8]
            tail = newNode; // The new node also becomes the tail [8]
        }
        // Case 2: If the linked list is not empty [8]
        else {
            tail->next = newNode; // The next pointer of the current tail points to the new node [8]
            tail = newNode; // The new node becomes the new tail [8]
        }
    }

    // Function to delete the first node from the linked list (pop front) [4, 9]
    void popFront() {
        // If the linked list is empty [10]
        if (head == nullptr) {
            std::cout << "LinkedList is empty" << std::endl;
            return;
        }

        Node* temp = head; // Store the current head in a temporary pointer [9, 10]
        head = head->next; // Move the head pointer to the next node [9, 10]
        temp->next = nullptr; // Disconnect the original head from the list [10]
        delete temp; // Delete the original head node from memory [9, 10]

        // If the list becomes empty after deletion, update tail as well [10]
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    // Function to delete the last node from the linked list (pop back) [4, 10]
    void popBack() {
        // If the linked list is empty [11, 12]
        if (head == nullptr) {
            std::cout << "LinkedList is empty" << std::endl;
            return;
        }

        // If there is only one node in the list [10]
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node* temp = head; // Start from the head [11, 13]
        // Traverse the list until the second last node is reached [11]
        while (temp->next != tail) {
            temp = temp->next;
        }

        temp->next = nullptr; // Break the connection from the second last node to the last node [11, 12]
        delete tail; // Delete the last node from memory [11, 12]
        tail = temp; // Update the tail to the second last node [11, 12]
    }

    // Function to insert a new node at a specific position in the linked list [4, 12]
    void insert(int value, int position) {
        // If the position is invalid (less than 0) [14, 15]
        if (position < 0) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        // If the position is 0, insert at the front (same as pushFront) [14, 15]
        if (position == 0) {
            pushFront(value);
            return;
        }

        // Create a new node [15, 16]
        Node* newNode = new Node(value);
        Node* temp = head;

        // Traverse to the node at position - 1 [15, 16]
        for (int i = 0; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        // If the position is out of bounds [17]
        if (temp == nullptr) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        newNode->next = temp->next; // The next of the new node points to the node at the specified position [14, 15]
        temp->next = newNode; // The next of the node at position - 1 points to the new node [14, 15]

        // If the new node is inserted at the end, update the tail [15]
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    // Function to print all the elements of the linked list [18]
    void printLinkedList() {
        Node* temp = head; // Start from the head [18, 19]
        while (temp != nullptr) { // Traverse until the end of the list (null pointer) [18, 19]
            std::cout << temp->data << " -> "; // Print the data of the current node [19]
            temp = temp->next; // Move to the next node [19]
        }
        std::cout << "nullptr" << std::endl; // Indicate the end of the list [19]
    }

    // Function to search for a key value in the linked list and return its index [4, 17]
    int search(int key) {
        Node* temp = head; // Start from the head [17]
        int index = 0; // Initialize index to 0 [17]
        while (temp != nullptr) { // Traverse the list [17, 20]
            if (temp->data == key) { // If the key is found [20]
                return index; // Return the current index [20]
            }
            temp = temp->next; // Move to the next node [20]
            index++; // Increment the index [20]
        }
        return -1; // If the key is not found, return -1 [20]
    }

    void middle()
    {
        Node* slow = head;
        Node* fast= head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        std::cout<<"Middle Element: "<<slow->data;
    }

};

int main() {
    List ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushFront(9);
    ll.pushFront(7);
    std::cout << "Original Linked List: ";
    ll.printLinkedList();
    ll.middle();
    return 0;
}
