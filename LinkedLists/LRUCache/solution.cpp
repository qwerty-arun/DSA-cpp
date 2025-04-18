#include <iostream>
#include <unordered_map>

class LRUCache {
private:
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int limit;
    std::unordered_map<int, Node*> map;
    Node* head;
    Node* tail;

    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    void deleteNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

public:
    LRUCache(int capacity) : limit(capacity), head(new Node(-1, -1)), tail(new Node(-1, -1)) {
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        Node* answerNode = map[key];
        deleteNode(answerNode);
        addNode(answerNode);
        map[key] = head->next;
        return answerNode->value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* oldNode = map[key];
            deleteNode(oldNode);
            map.erase(key);
        }
        if (map.size() == limit) {
            Node* temp = tail->prev;
            map.erase(temp->key);
            deleteNode(temp);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        map[key] = head->next;
    }
};

int main() {
    LRUCache lruCache(2);
    lruCache.put(1, 1);
    lruCache.put(2, 2);
    std::cout << lruCache.get(1) << std::endl;
    lruCache.put(3, 3);
    std::cout << lruCache.get(2) << std::endl;
    lruCache.put(4, 4);
    std::cout << lruCache.get(1) << std::endl;
    std::cout << lruCache.get(3) << std::endl;
    std::cout << lruCache.get(4) << std::endl;
    return 0;
}
