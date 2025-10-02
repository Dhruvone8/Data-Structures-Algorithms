// Place N Queens on a N x N Board such that no Queen each other

/* 
Time Complexity: O(N!)
Space Complexity: O(N*N)
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &Elements, int row, int col, int n)
{
    // For Vertical Row
    for (int i = 0; i < row; i++)
    {
        if (Elements[i][col] == 'Q')
        {
            return false;
        }
    }

    // For Left Diagonal
    int MaxLeft = min(row, col);
    for (int i = 1; i <= MaxLeft; i++)
    {
        if (Elements[row - i][col - i] == 'Q')
        {
            return false;
        }
    }

    // For Right Diagonal
    int rightcol = n - col - 1;
    int MaxRight = min(row, rightcol);
    for (int i = 1; i <= MaxRight; i++)
    {
        if (Elements[row - i][col + i] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void solve(vector<string> &Elements, int row, vector<vector<string>> &board, int n)
{
    if (row == n)
    {
        board.push_back(Elements);
        return;
    }

    // Placing the Queen and checking for every row and column

    for (int col = 0; col < n; col++)
    {
        // Place the Queen if its Safe
        if (isSafe(Elements, row, col, n))
        {
            Elements[row][col] = 'Q';
            solve(Elements, row + 1, board, n);
            Elements[row][col] = '.';
        }
    }
}

vector<vector<string>> solveQueens(int n)
{
    vector<string> Elements(n, string(n, '.'));
    vector<vector<string>> board;
    solve(Elements, 0, board, n);
    return board;
}

int main()
{
    vector<vector<string>> board = solveQueens(4);
    for (vector<string> row : board)
    {
        for (string elements : row)
        {
            cout << elements << endl;
        }
        cout << endl;
    }
    return 0;
}

