# Sudoku Solver
- We have a board (9x9) with some digits already placed.
- Solve the problem using recursion

## Intuition
- Checking condition: 1) Horizontal, 2) Vertical and 3) Grid
- If anyone fails, we can't place the digit
- We run a loop of digit=1 to 9
- Then, we check the conditions.
- Place the digit as long as it is safe even if it is not the right position
- Then a point comes where we need to place the only missing no in the row or column but it turns out that it is not safe, therefore the digit placement before wasn't right, so we need to backtrack now.
