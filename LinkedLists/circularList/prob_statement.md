# Reverse Linked List (LeetCode 206)
- Given the head of a singly linked list, return the reversed list

## Approach
- We will be using three pointers: prev, current and next
- current starts with head
- next = current->next
- current -> next = prev
- prev = current
- current = next

## My Approach
- Implement a stack and copy the elements from the linked list to the stack
