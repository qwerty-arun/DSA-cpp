#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
    stack<long long> s;
    long long minVal;

public:
    MinStack() {
        // Constructor
    }

    void push(int value) {
        long long val = value;
        if (s.empty()) {
            minVal = val;
            s.push(val);
        } else if (val < minVal) {
            s.push(2 * val - minVal); // Encoded value
            minVal = val;
        } else {
            s.push(val);
        }
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() < minVal) {
            minVal = 2 * minVal - s.top(); // Restore previous minVal
        }
        s.pop();
    }

    int top() {
        if (s.empty()) return -1; // Or handle empty case as needed
        if (s.top() < minVal) {
            return minVal; // Top element is encoded, actual top is minVal
        } else {
            return s.top();
        }
    }

    int getMin() {
        return minVal;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "getMin: " << minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << "top: " << minStack.top() << endl;    // return 0
    cout << "getMin: " << minStack.getMin() << endl; // return -2
    return 0;
}
