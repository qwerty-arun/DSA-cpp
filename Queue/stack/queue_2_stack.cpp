#include <stack>

class MyQueue {
public:
    std::stack<int> s1;
    std::stack<int> s2;

    MyQueue() {
        // Constructor can be left empty [3]
    }

    void push(int x) {
        // Copy all elements from s1 to s2 [3]
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // Push the new element x into s1 [3]
        s1.push(x);
        // Copy all elements back from s2 to s1 [3]
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        // Store the top element of s1 (which is the front of the queue) [3]
        int frontElement = s1.top();
        // Pop the element from s1 [3]
        s1.pop();
        // Return the popped element [3]
        return frontElement;
    }

    int peek() {
        // Return the top element of s1 (which is the front of the queue) [3]
        return s1.top();
    }

    bool empty() {
        // Return true if s1 is empty, false otherwise [3]
        return s1.empty();
    }
};
