# Flatten Multilevel Doubly Linked List (LeetCode 430)
- Implement the doubly linked lists
```cpp
class Node
{
    int data;
    Node* next;
    Node* prev;
    Node* child;
};
```
- The child pointer may or may not point to a separate doubly linked list, also containing these special nodes
- These child lists may have one or more children of their own, and so on, to produce a multilevel data structure
- Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. 
- Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list
- Return the head of the flattened list. th nodes in the list must have all of their child pointers set to null

- Example: 1 <-> 2 <-> 3 <-> 4 <-> 5
-                      |
-                      V
-                      6 <-> 7 <-> 8
-                            |
-                            V
-                            9 <-> 10

- Answer: 1 <-> 2 <-> 3 <-> 6 <-> 7 <-> 9 <-> 10 <-> 8 <-> 4 <-> 5
