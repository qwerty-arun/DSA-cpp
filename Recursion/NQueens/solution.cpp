#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n)
{
    // Horizontal
    for(int i = 0; i < n; i++)
        if(board[row][i] == 'Q') return false;

    // Vertical
    for(int i = 0; i < n; i++)
        if(board[i][col] == 'Q') return false;

    // Left Diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j] == 'Q') return false;

    // Right Diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++)
        if(board[i][j] == 'Q') return false;

    return true;
}

void NQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans)
{
    if(row == n)
    {
        ans.push_back(board);  // Save the board
        cout << "Solution #" << ans.size() << ":\n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout << board[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for(int j=0; j<n; j++)
    {
        if(isSafe(board, row, j, n))
        {
            board[row][j] = 'Q';
            NQueens(board, row+1, n, ans);
            board[row][j] = '.';
        }
    }
}

int main()
{
    int n = 4;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    NQueens(board, 0, n, ans);
    cout << "Total Solutions: " << ans.size() << endl;
}

