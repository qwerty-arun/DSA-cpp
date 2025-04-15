# Identical Tree (Leetcode 100)
- Given the roots of two binary trees p and q, write a function to check if they are the same
- Two binary trees are considered the same if they are structurally identical and nodes have same values
```mermaid
graph TD;
A[1]-->B[2]
A[1]-->C[3]
D[1]-->E[2]
D[1]-->F[3]
```
- Answer is true for the above
```mermaid
graph TD;
A[1]-->B[2]
A[1]-->C[nullptr]
D[1]-->E[nullptr]
D[1]-->F[3]
```
- Answer is false for the above

