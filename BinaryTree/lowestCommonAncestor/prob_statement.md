# Lowest Common Ancestor (Leetcode: 236)
- Find LCA for the two nodes 'p' and 'q'
- Suppose the following tree: p is 5 and q is 7
```mermaid
graph TD;
    A[1]-->B[2]
    A[1]-->C[3]
    B[2]-->C[4]
    B[2]-->D[5]
    D[5]-->E[8]
    D[5]-->E[9]
    C[3]-->F[6]
    C[3]-->F[7]
```
- A node is an ancestor of the own
- The answer will be 1 in this case
- Redefinition of the problem: Find the node for which, p and q exists in the subtrees
