/*
A Valid Sudoku must have
1. 1-9 numbers exactly once in every row
2. 1-9 numbers exactly once in every column
3. 1-9 numbers exactly once in every 3x3 sub-matrix
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        // Check Whether c is present in every row of that column
        if (board[i][col] == c)
        {
            return false;
        }

        // Check Whether c is present in every column of that row
        if (board[row][i] == c)
        {
            return false;
        }

        // Check whether c is present in its 3x3 matrix
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        {
            return false;
        }
    }

    // If none of the above conditions satisfy
    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, row, col, c))
                    {
                        board[row][col] = c;
                        if (solve(board) == true)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{
    vector<vector<char>> board = 
    { 
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, 
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, 
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, 
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, 
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, 
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, 
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, 
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, 
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    solveSudoku(board);
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}