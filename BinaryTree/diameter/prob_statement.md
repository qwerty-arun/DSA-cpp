# Diameter of Binary Tree (Leetcode 543)
- Given the root, return the diameter of the tree
- The diameter of a binary tree is the length of the longest path between any two noes in a tree which may or may not pass through the root
- The length of a path between two nodes by the number of edges between them

## Case-1
- If the diameter passes through the root node: then the diameter = leftHt + rightHt

## Case-2
- Right Diameter or Left Diameter

- We will calculate all the three values for all the nodes and then the max value will be the answer
