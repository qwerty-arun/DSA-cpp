#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HashEntry {
public:
    int key;
    string value;
    bool isDeleted;

    HashEntry(int key, string value) : key(key), value(value), isDeleted(false) {}
};

class HashTable {
private:
    vector<HashEntry*> table;
    int capacity;
    int size;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTable(int capacity) : capacity(capacity), size(0) {
        table.resize(capacity, nullptr);
    }

    void put(int key, const string& value) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != nullptr && !table[index]->isDeleted && table[index]->key != key) {
            index = (index + 1) % capacity;
            if (index == startIndex) {
                cout << "Hash table is full!\n";
                return;
            }
        }

        if (table[index] == nullptr || table[index]->isDeleted) {
            if (table[index] != nullptr) delete table[index]; // clean deleted
            table[index] = new HashEntry(key, value);
            size++;
        } else {
            table[index]->value = value; // update existing key
        }
    }

    string get(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != nullptr) {
            if (!table[index]->isDeleted && table[index]->key == key) {
                return table[index]->value;
            }
            index = (index + 1) % capacity;
            if (index == startIndex) break;
        }

        return "Not Found";
    }

    void remove(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != nullptr) {
            if (!table[index]->isDeleted && table[index]->key == key) {
                table[index]->isDeleted = true;
                size--;
                return;
            }
            index = (index + 1) % capacity;
            if (index == startIndex) break;
        }
    }

    ~HashTable() {
        for (auto entry : table) {
            delete entry;
        }
    }
};
