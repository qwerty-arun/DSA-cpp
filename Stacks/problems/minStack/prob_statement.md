# Min Stack (LeetCode 155)

## 1st Approach: O(2*n)
- The push operation adds a pair containing the value and the current minimum. If the stack is empty, the minimum is the value itself. Otherwise, the minimum is the smaller of the current value and the minimum stored in the top pair.
- The pop operation simply removes the top pair from the stack.
- The top operation returns the first element (the value) of the top pair.
- The getMin operation returns the second element (the minimum value) of the top pair. This ensures a constant time complexity for getMin.
- The space complexity of this approach is O(n) because for every element pushed, we store a pair in the stack.

## 2nd Approach: O(n)
- The push operation checks if the new value val is less than the current minVal.
- If it is, a special encoded value 2 * val - minVal is pushed onto the stack, and minVal is updated to val. This encoding helps in retrieving the previous minimum when the current minimum is popped.
- If val is greater than or equal to minVal, it is directly pushed onto the stack.
- If the stack is empty, the value is pushed, and minVal is set to that value.
- The pop operation checks if the top of the stack is less than the current minVal.
- If it is, it means an encoded minimum value is being popped. The previous minVal is restored using the formula 2 * minVal - s.top(), and then the top element is popped.
- Otherwise, the top element is simply popped.
- The top operation checks if the top of the stack is less than minVal.
- If it is, the actual top value was the minVal before the encoded value was pushed, so minVal is returned.
- Otherwise, the top element is the actual value, so s.top() is returned.
- The getMin operation simply returns the current minVal, ensuring constant time complexity.
- The space complexity: O(n)
