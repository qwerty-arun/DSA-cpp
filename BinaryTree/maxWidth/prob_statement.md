# Maximum Width of Binary Tree (LeetCode: 692)
- Longest length between the end-nodes where the null nodes between the end-nodes that would be present in a complete binary tree
```mermaid
graph TD;
    A[1]-->B[3];
    A[1]-->C[2];
    B[3]-->D[5];
    B[3]-->E[3];
    C[2]-->F[9];
```
- For the above tree, it is 4
- We will use the concept of Complete Binary Tree Index (CBT)
- An array will be used
- The array will be: 1 3 2 5 3 '' 9
- General formula for width at a level: endIdx - stIdx + 1
