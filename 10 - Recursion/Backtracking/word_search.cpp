#include <iostream>
#include <vector>
using namespace std;

bool searchNext(int index, int rows, int cols, vector<vector<char>> &board, string& word)
{
    if (index == word.size())
    {
        return true;
    }

   if (rows < 0 || cols < 0 || rows >= board.size() || cols >= board[0].size() || board[rows][cols] != word[index])
    {
        return false;
    }

    // Store the character of the cell you are visiting in a variable
    char c = board[rows][cols];

    // Mark the visited cell to prevent traversing the same cell again
    board[rows][cols] = '$';

    // Traverse Downwards
    if (searchNext(index + 1, rows + 1, cols, board, word) == true)
    {
        return true;
    }

    // Traverse Right
    if (searchNext(index + 1, rows, cols + 1, board, word) == true)
    {
        return true;
    }

    // Traverse Upwards
    if (searchNext(index + 1, rows - 1, cols, board, word) == true)
    {
        return true;
    }

    // Traverse Left
    if (searchNext(index + 1, rows, cols - 1, board, word) == true)
    {
        return true;
    }

    // Undo the change you did after the recursion call is completed
    board[rows][cols] = c;

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int index = 0;
    // Linearly traverse the matrix to find the first letter of the word
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[0] && (searchNext(index, i, j, board, word) == true))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = { {'A', 'B', 'C', 'E'},
                                   {'S', 'F', 'C', 'S'},
                                   {'A', 'D', 'E', 'E'} };

    cout << exist(board, "ABCCED");
    return 0;
}