#include <queue>

class MyStack {
public:
    std::queue<int> q1;
    std::queue<int> q2;

    MyStack() {
        // Constructor can be left empty [2]
    }

    void push(int x) {
        // Copy all elements from q1 to q2 [2]
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Push the new element x into q1 [2]
        q1.push(x);
        // Copy all elements back from q2 to q1 [2]
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        // Store the front element of q1 (which is the top of the stack) [2]
        int topElement = q1.front();
        // Pop the element from q1 [2]
        q1.pop();
        // Return the popped element [2]
        return topElement;
    }

    int top() {
        // Return the front element of q1 (which is the top of the stack) [2]
        return q1.front();
    }

    bool empty() {
        // Return true if q1 is empty, false otherwise [2]
        return q1.empty();
    }
};
