#include <iostream>
#include <optional>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdexcept>
#include <string>

template <typename T>
class BinaryHeapQuickRemovals {
private:
    std::vector<T> heap;
    std::map<T, std::set<int>> map;

    bool less(int i, int j) const {
        return heap[i] <= heap[j];
    }

    void swim(int k) {
        int parent = (k - 1) / 2;
        while (k > 0 && less(k, parent)) {
            swap(parent, k);
            k = parent;
            parent = (k - 1) / 2;
        }
    }

    void sink(int k) {
        int heapSize = size();
        while (true) {
            int left = 2 * k + 1;
            int right = 2 * k + 2;
            int smallest = left;

            if (right < heapSize && less(right, left)) {
                smallest = right;
            }

            if (left >= heapSize || less(k, smallest)) {
                break;
            }

            swap(smallest, k);
            k = smallest;
        }
    }

    void swap(int i, int j) {
        T i_elem = heap[i];
        T j_elem = heap[j];
        heap[i] = j_elem;
        heap[j] = i_elem;
        mapSwap(i_elem, j_elem, i, j);
    }

    void mapAdd(const T& value, int index) {
        auto it = map.find(value);
        if (it == map.end()) {
            std::set<int> set;
            set.insert(index);
            map[value] = set;
        } else {
            it->second.insert(index);
        }
    }

    void mapRemove(const T& value, int index) {
        auto it = map.find(value);
        if (it != map.end()) {
            it->second.erase(index);
            if (it->second.empty()) {
                map.erase(it);
            }
        }
    }

    std::optional<int> mapGet(const T& value) const {
        auto it = map.find(value);
        if (it != map.end() && !it->second.empty()) {
            return *it->second.rbegin(); // Returns the highest index
        }
        return std::nullopt;
    }

    void mapSwap(const T& val1, const T& val2, int val1Index, int val2Index) {
        auto it1 = map.find(val1);
        auto it2 = map.find(val2);
        if (it1 != map.end()) {
            it1->second.erase(val1Index);
            it1->second.insert(val2Index);
        }
        if (it2 != map.end()) {
            it2->second.erase(val2Index);
            it2->second.insert(val1Index);
        }
    }

    T removeAt(int i) {
        if (isEmpty()) {
            return T{}; // Or throw an exception
        }
        int indexOfLastElem = size() - 1;
        T removed_data = heap[i];
        swap(i, indexOfLastElem);
        heap.pop_back();
        mapRemove(removed_data, indexOfLastElem);

        if (i == indexOfLastElem) {
            return removed_data;
        }

        T elem = heap[i];
        sink(i);
        if (heap[i] == elem) {
            swim(i);
        }
        return removed_data;
    }

    bool isMinHeapRecursive(int k) const {
        int heapSize = size();
        if (k >= heapSize) {
            return true;
        }
        int left = 2 * k + 1;
        int right = 2 * k + 2;

        if (left < heapSize && !less(k, left)) {
            return false;
        }
        if (right < heapSize && !less(k, right)) {
            return false;
        }
        return isMinHeapRecursive(left) && isMinHeapRecursive(right);
    }

public:
    BinaryHeapQuickRemovals() {}

    explicit BinaryHeapQuickRemovals(int sz) : heap(sz) {}

    BinaryHeapQuickRemovals(T arr[], int n) : heap(arr, arr + n) {
        int heapSize = size();
        for (int i = std::max(0, (heapSize / 2) - 1); i >= 0; --i) {
            sink(i);
        }
        for (int i = 0; i < heapSize; ++i) {
            mapAdd(heap[i], i);
        }
    }

    BinaryHeapQuickRemovals(const std::vector<T>& elems) : heap(elems) {
        int heapSize = size();
        for (int i = std::max(0, (heapSize / 2) - 1); i >= 0; --i) {
            sink(i);
        }
        for (int i = 0; i < heapSize; ++i) {
            mapAdd(heap[i], i);
        }
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void clear() {
        heap.clear();
        map.clear();
    }

    int size() const {
        return heap.size();
    }

    T peek() const {
        if (isEmpty()) {
            return T{}; // Or throw an exception
        }
        return heap.front();
    }

    T poll() {
        return removeAt(0);
    }

    bool contains(const T& elem) const {
        return map.count(elem) > 0;
    }

    void add(const T& elem) {
        if (elem == T{}) { // Simulate null check using default constructor
            throw std::invalid_argument("Element cannot be null");
        }
        heap.push_back(elem);
        int indexOfLastElem = size() - 1;
        mapAdd(elem, indexOfLastElem);
        swim(indexOfLastElem);
    }

    bool remove(const T& element) {
        if (element == T{}) { // Simulate null check
            return false;
        }
        auto index = mapGet(element);
        if (index.has_value()) {
            removeAt(index.value());
            return true;
        }
        return false;
    }

    bool isMinHeap() const {
        return isMinHeapRecursive(0);
    }

    std::string toString() const {
        std::string s = "[";
        for (size_t i = 0; i < heap.size(); ++i) {
            s += (i == 0 ? "" : ", ") + std::to_string(heap[i]);
        }
        s += "]";
        return s;
    }
};

int main() {
    // Example usage of the BinaryHeapQuickRemovals class

    // Create an empty min-heap
    BinaryHeapQuickRemovals<int> minHeap;
    std::cout << "Is minHeap empty? " << minHeap.isEmpty() << std::endl;

    // Add some elements
    minHeap.add(3);
    minHeap.add(1);
    minHeap.add(4);
    minHeap.add(1);
    minHeap.add(5);
    minHeap.add(9);
    minHeap.add(2);
    minHeap.add(6);

    std::cout << "Min-Heap after adding elements: " << minHeap.toString() << std::endl;

    // Peek at the smallest element
    if (!minHeap.isEmpty()) {
        std::cout << "Peek smallest element: " << minHeap.peek() << std::endl;
    }

    // Poll (remove) the smallest element
    std::cout << "Poll smallest element: " << minHeap.poll() << std::endl;
    std::cout << "Min-Heap after poll: " << minHeap.toString() << std::endl;

    // Check if an element exists
    std::cout << "Does minHeap contain 4? " << minHeap.contains(4) << std::endl;
    std::cout << "Does minHeap contain 10? " << minHeap.contains(10) << std::endl;

    // Remove a specific element
    std::cout << "Remove element 5: " << minHeap.remove(5) << std::endl;
    std::cout << "Min-Heap after removing 5: " << minHeap.toString() << std::endl;

    std::cout << "Current size of minHeap: " << minHeap.size() << std::endl;

    // Create a min-heap from an array
    int arr[] = {5, 1, 4, 2, 8};
    BinaryHeapQuickRemovals<int> minHeapFromArray(arr, sizeof(arr) / sizeof(arr));
    std::cout << "Min-Heap created from array: " << minHeapFromArray.toString() << std::endl;

    // Create a min-heap from a vector
    std::vector<int> vec = {9, 3, 7, 0, 6};
    BinaryHeapQuickRemovals<int> minHeapFromVector(vec);
    std::cout << "Min-Heap created from vector: " << minHeapFromVector.toString() << std::endl;

    std::cout << "Is minHeap a valid min-heap? " << minHeap.isMinHeap() << std::endl;
    std::cout << "Is minHeapFromArray a valid min-heap? " << minHeapFromArray.isMinHeap() << std::endl;
    std::cout << "Is minHeapFromVector a valid min-heap? " << minHeapFromVector.isMinHeap() << std::endl;

    // Clear the heap
    minHeap.clear();
    std::cout << "Min-Heap after clear: " << minHeap.toString() << std::endl;
    std::cout << "Is minHeap empty after clear? " << minHeap.isEmpty() << std::endl;

    return 0;
}
