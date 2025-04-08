#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, int digit)
{
    // Row
    for(char j = '0';j<'9';j++)
    {
        if(board[row][j] == digit)
            return false;
    }

    // Column
    for(char i = '0';i<'9';i++)
    {
        if(board[i][col] == digit)
            return false;
    }

    //We need to find out in which grid the digit lies
    int startRow = (row/3) * 3;
    int startCol = (col/3) * 3;

    for(int i=startRow;i<=startRow+2;i++)
    {
        for(int j=startCol;j<=startCol;j++)
        {
            if(board[i][j]==digit)
                return false;
        }
    }
    return true;
}

bool SudokoSolver(vector<vector<char>>& board, int row, int col)
{
    if(row == 9)
        return true;

    int nextRow = row, nextCol = col+1;
    if(nextCol == 9)
    {
        nextRow= row+1;
        nextCol = 0;
    }

    if(board[row][col]!='.')
        return SudokoSolver(board, row, col+1);

    for(int digit = 1; digit<=9; digit++)
    {
        if(isSafe(board, row, col, digit))
        {
            board[row][col] = digit;
            if(SudokoSolver(board, nextRow, nextCol))
            {
                return true;
            }
            board[row][col] ='.';
        }
    }

    return false;
}

int main()
{
    int n = 9;
    vector<vector<char>> board('.');
    SudokoSolver(board, 0, 0);
}

