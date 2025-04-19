#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>

template <typename T>
class BinaryHeap {
private:
    std::vector<T> heap;

    // Tests if the value of node i <= node j
    bool less(int i, int j) const {
        return heap[i] <= heap[j];
    }

    void swim(int k) {
        int parent = (k - 1) / 2;
        while (k > 0 && less(k, parent)) {
            std::swap(heap[parent], heap[k]);
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

            std::swap(heap[smallest], heap[k]);
            k = smallest;
        }
    }

    void swap(int i, int j) {
        std::swap(heap[i], heap[j]);
    }

    T removeAt(int i) {
        if (isEmpty()) {
            return T{}; // Or throw an exception
        }
        int indexOfLastElem = size() - 1;
        T removed_data = heap[i];
        swap(i, indexOfLastElem);
        heap.pop_back();

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
    BinaryHeap() {}

    BinaryHeap(int sz) : heap(sz) {}

    BinaryHeap(T arr[], int n) : heap(arr, arr + n) {
        int heapSize = size();
        for (int i = std::max(0, (heapSize / 2) - 1); i >= 0; --i) {
            sink(i);
        }
    }

    BinaryHeap(const std::vector<T>& elems) : heap(elems) {
        int heapSize = size();
        for (int i = std::max(0, (heapSize / 2) - 1); i >= 0; --i) {
            sink(i);
        }
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void clear() {
        heap.clear();
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
        return std::find(heap.begin(), heap.end(), elem) != heap.end();
    }

    void add(const T& elem) {
        heap.push_back(elem);
        swim(size() - 1);
    }

    bool remove(const T& element) {
        auto it = std::find(heap.begin(), heap.end(), element);
        if (it != heap.end()) {
            removeAt(std::distance(heap.begin(), it));
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
    // Example usage of the BinaryHeap class

    // Create an empty min-heap
    BinaryHeap<int> minHeap;
    std::cout << "Is minHeap empty? " << minHeap.isEmpty() << std::endl; // Output: Is minHeap empty? 1

    // Add some elements
    minHeap.add(3);
    minHeap.add(1);
    minHeap.add(4);
    minHeap.add(1);
    minHeap.add(5);
    minHeap.add(9);
    minHeap.add(2);
    minHeap.add(6);

    std::cout << "Min-Heap after adding elements: " << minHeap.toString() << std::endl; // Output will vary depending on internal ordering

    // Peek at the smallest element
    if (!minHeap.isEmpty()) {
        std::cout << "Peek smallest element: " << minHeap.peek() << std::endl; // Output: Peek smallest element: 1
    }

    // Poll (remove) the smallest element
    std::cout << "Poll smallest element: " << minHeap.poll() << std::endl; // Output: Poll smallest element: 1
    std::cout << "Min-Heap after poll: " << minHeap.toString() << std::endl;

    // Check if an element exists
    std::cout << "Does minHeap contain 4? " << minHeap.contains(4) << std::endl; // Output: Does minHeap contain 4? 1
    std::cout << "Does minHeap contain 10? " << minHeap.contains(10) << std::endl; // Output: Does minHeap contain 10? 0

    // Remove a specific element
    std::cout << "Remove element 5: " << minHeap.remove(5) << std::endl; // Output: Remove element 5: 1
    std::cout << "Min-Heap after removing 5: " << minHeap.toString() << std::endl;

    std::cout << "Current size of minHeap: " << minHeap.size() << std::endl;

    // Create a min-heap from an array
    int arr[] = {5, 1, 4, 2, 8};
    BinaryHeap<int> minHeapFromArray(arr, sizeof(arr) / sizeof(arr));
    std::cout << "Min-Heap created from array: " << minHeapFromArray.toString() << std::endl;

    // Create a min-heap from a vector
    std::vector<int> vec = {9, 3, 7, 0, 6};
    BinaryHeap<int> minHeapFromVector(vec);
    std::cout << "Min-Heap created from vector: " << minHeapFromVector.toString() << std::endl;

    std::cout << "Is minHeap a valid min-heap? " << minHeap.isMinHeap() << std::endl;
    std::cout << "Is minHeapFromArray a valid min-heap? " << minHeapFromArray.isMinHeap() << std::endl;
    std::cout << "Is minHeapFromVector a valid min-heap? " << minHeapFromVector.isMinHeap() << std::endl;

    // Clear the heap
    minHeap.clear();
    std::cout << "Min-Heap after clear: " << minHeap.toString() << std::endl;
    std::cout << "Is minHeap empty after clear? " << minHeap.isEmpty() << std::endl; // Output: Is minHeap empty after clear? 1

    return 0;
}
