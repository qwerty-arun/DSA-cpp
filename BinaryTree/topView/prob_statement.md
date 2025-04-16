# Top View of the tree
- Suppose the following tree:
```mermaid
graph TD;
    A[1]-->B[2]
    A[1]-->C[3]
    C[3]-->D[4]
    C[3]-->E[5]
```
- The top view will be: 2 1 3 5
- 4 isn't printed because it is directly below 1

## Horizontal Distance and Level Order Traversal
- root = origin, left= -1 and right = +1
- Find the distance for each node
- See how many elements have the same distance
- If many elements have the same distance, then see which element comes first in the level order traversal, then print it
