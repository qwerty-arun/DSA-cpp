# Rat in a Maze Problem
- We have a 4x4 matrix, with 1s and 0s
- Starting with (0,0) and ending at (n-1)(n-1), find all possible paths which we can take
- You can't step on '0', even if you do, you can't move forward
- We must always move on '1s'
- If we have maze[0][0] or maze [n-1][n-1] == 0, then there is no solution
- We can step on a cell only once.

## Intuition
- For each cell, we can move forward, backward, left or right.
- We need to check boundary conditions.
- We need another matrix ans[][] to check for visit
