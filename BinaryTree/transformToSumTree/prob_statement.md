# Transform to Sum Tree 
- Suppose the following tree:
```mermaid
graph TD;
    A[1]-->B[2]
    A[1]-->C[3]
    C[3]-->D[4]
    C[3]-->E[5]
```
- node = node value + left subtree + right subtree
