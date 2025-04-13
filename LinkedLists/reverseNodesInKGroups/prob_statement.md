# Reverse Nodes in K-Group (Leetcode 25)
- Given the head of a linked list, reverse the nodes list `k` at a time, and return the modified list
- `k` is a positive integer and is less than or equal to length of the list.
- If number of nodes is a multiple of `k` then left-out nodes, in the end, should remain as it is.
- You may or may not alter the values in the list's nodes, nodes themselves may be changed.
- Example: 1->2->3->4->5->nullptr and k=2
- Answer: 2->1->4->3->5->nullptr

- Example: 1->2->3->4->5->nullptr and k=3
- Answer: 3->2->1->4->5->nullptr

## Steps
- Check if k nodes exists
- recursively call for rest of the ll
- reverse the current group
