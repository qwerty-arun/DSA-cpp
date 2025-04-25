#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <utility>

template <typename K, typename V>
class HashTableSeparateChaining {
private:
    struct Entry {
        K key;
        V value;
        std::size_t hash;

        Entry(const K& k, const V& v) : key(k), value(v), hash(std::hash<K>{}(k)) {}

        bool operator==(const Entry& other) const {
            return hash == other.hash && key == other.key;
        }
    };

    static constexpr int DEFAULT_CAPACITY = 3;
    static constexpr double DEFAULT_LOAD_FACTOR = 0.75;

    std::vector<std::list<Entry>> table;
    int capacity;
    double maxLoadFactor;
    int threshold;
    int size;

    int normalizeIndex(std::size_t hash) const {
        return static_cast<int>(hash & 0x7FFFFFFF) % capacity;
    }

    void resizeTable() {
        capacity *= 2;
        threshold = static_cast<int>(capacity * maxLoadFactor);
        std::vector<std::list<Entry>> newTable(capacity);

        for (const auto& bucket : table) {
            for (const auto& entry : bucket) {
                int bucketIndex = normalizeIndex(entry.hash);
                newTable[bucketIndex].push_back(entry);
            }
        }

        table = std::move(newTable);
    }

    typename std::list<Entry>::iterator findEntry(int index, const K& key) {
        return std::find_if(table[index].begin(), table[index].end(),
                            [&key](const Entry& e) { return e.key == key; });
    }

public:
    HashTableSeparateChaining(int initCapacity = DEFAULT_CAPACITY, double loadFactor = DEFAULT_LOAD_FACTOR)
        : maxLoadFactor(loadFactor), size(0) {
        if (initCapacity < 0 || maxLoadFactor <= 0.0 || !std::isfinite(maxLoadFactor)) {
            throw std::invalid_argument("Illegal capacity or load factor");
        }
        capacity = std::max(initCapacity, DEFAULT_CAPACITY);
        threshold = static_cast<int>(capacity * maxLoadFactor);
        table.resize(capacity);
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    bool containsKey(const K& key) {
        int index = normalizeIndex(std::hash<K>{}(key));
        return findEntry(index, key) != table[index].end();
    }

    V get(const K& key) {
        int index = normalizeIndex(std::hash<K>{}(key));
        auto it = findEntry(index, key);
        return (it != table[index].end()) ? it->value : V{};
    }

    V put(const K& key, const V& value) {
        Entry newEntry(key, value);
        int index = normalizeIndex(newEntry.hash);
        auto it = findEntry(index, key);

        if (it == table[index].end()) {
            table[index].push_back(newEntry);
            if (++size > threshold) resizeTable();
            return V{};
        } else {
            V oldValue = it->value;
            it->value = value;
            return oldValue;
        }
    }

    V remove(const K& key) {
        int index = normalizeIndex(std::hash<K>{}(key));
        auto it = findEntry(index, key);
        if (it != table[index].end()) {
            V value = it->value;
            table[index].erase(it);
            --size;
            return value;
        }
        return V{};
    }

    std::vector<K> keys() const {
        std::vector<K> keys;
        for (const auto& bucket : table)
            for (const auto& entry : bucket)
                keys.push_back(entry.key);
        return keys;
    }

    std::vector<V> values() const {
        std::vector<V> vals;
        for (const auto& bucket : table)
            for (const auto& entry : bucket)
                vals.push_back(entry.value);
        return vals;
    }

    void clear() {
        for (auto& bucket : table) {
            bucket.clear();
        }
        size = 0;
    }

    void print() const {
        std::cout << "{ ";
        for (const auto& bucket : table)
            for (const auto& entry : bucket)
                std::cout << entry.key << " => " << entry.value << ", ";
        std::cout << "}\n";
    }
};
