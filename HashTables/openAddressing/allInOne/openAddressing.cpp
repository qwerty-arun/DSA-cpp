#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum ProbingType { LINEAR, QUADRATIC, DOUBLE_HASH };

class HashTable {
private:
    vector<string> table;
    int capacity;
    int size;
    ProbingType probingType;

    // Hash functions
    int hash1(const string& key) const {
        int hash = 0;
        for (char ch : key)
            hash = (hash * 31 + ch) % capacity;
        return hash;
    }

    int hash2(const string& key) const {
        int hash = 0;
        for (char ch : key)
            hash = (hash * 17 + ch) % capacity;
        // Ensure hash2 is never 0
        return (hash % (capacity - 1)) + 1;
    }

    int probe(int hash, int i, const string& key) const {
        switch (probingType) {
            case LINEAR:
                return (hash + i) % capacity;
            case QUADRATIC:
                return (hash + i * i) % capacity;
            case DOUBLE_HASH:
                return (hash + i * hash2(key)) % capacity;
        }
        return -1; // Should not reach
    }

public:
    HashTable(int cap, ProbingType pt) : capacity(cap), size(0), probingType(pt) {
        table.assign(capacity, "");
    }

    bool insert(const string& key) {
        if (size == capacity) {
            cout << "Hash table is full\n";
            return false;
        }

        int hash = hash1(key);
        int i = 0;
        int index;

        while (i < capacity) {
            index = probe(hash, i, key);
            if (table[index].empty()) {
                table[index] = key;
                size++;
                return true;
            }
            i++;
        }

        cout << "Failed to insert key: " << key << "\n";
        return false;
    }

    int search(const string& key) const {
        int hash = hash1(key);
        int i = 0;
        int index;

        while (i < capacity) {
            index = probe(hash, i, key);
            if (table[index] == key)
                return index;
            if (table[index].empty()) // Stop if empty slot found
                return -1;
            i++;
        }

        return -1;
    }

    void display() const {
        for (int i = 0; i < capacity; ++i)
            cout << i << " --> " << (table[i].empty() ? "[Empty]" : table[i]) << '\n';
    }
};

// Demo
int main() {
    int capacity = 11;

    cout << "Using Linear Probing:\n";
    HashTable htLinear(capacity, LINEAR);
    htLinear.insert("apple");
    htLinear.insert("banana");
    htLinear.insert("grape");
    htLinear.insert("orange");
    htLinear.display();
    cout << "Search 'banana': Index = " << htLinear.search("banana") << "\n\n";

    cout << "Using Quadratic Probing:\n";
    HashTable htQuadratic(capacity, QUADRATIC);
    htQuadratic.insert("apple");
    htQuadratic.insert("banana");
    htQuadratic.insert("grape");
    htQuadratic.insert("orange");
    htQuadratic.display();
    cout << "Search 'banana': Index = " << htQuadratic.search("banana") << "\n\n";

    cout << "Using Double Hashing:\n";
    HashTable htDouble(capacity, DOUBLE_HASH);
    htDouble.insert("apple");
    htDouble.insert("banana");
    htDouble.insert("grape");
    htDouble.insert("orange");
    htDouble.display();
    cout << "Search 'banana': Index = " << htDouble.search("banana") << "\n";

    return 0;
}
