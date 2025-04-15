#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
    stack<pair<int, int>> s;

public:
    MinStack() {
        // Constructor
    }

    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
        } else {
            s.push({val, min(val, s.top().second)});
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
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
