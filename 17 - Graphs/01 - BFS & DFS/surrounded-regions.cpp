// Leetcode Link: https://leetcode.com/problems/surrounded-regions

#include <bits/stdc++.h>
using namespace std;

// Set of O's connected to boundary cannot be considered as surrounded
// A O should be connected to X in all 4 directions

// Approach: Start from boundary O's and mark them that they can't be converted
// Convert the remaining O's

void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &board)
{
    visited[row][col] = 1;

    // Check for all 4 directions and find the O's connected to the edge
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dr[i];
        int ncol = col + dc[i];

        if (nrow >= 0 && ncol >= 0 && nrow < board.size() && ncol < board[0].size() && !visited[nrow][ncol] && board[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, visited, board);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();

    // A Matrix to mark visited cells
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // Traverse the first and the last row
    for (int i = 0; i < m; i++)
    {
        // First Row
        if (!visited[0][i] && board[0][i] == 'O')
        {
            dfs(0, i, visited, board);
        }

        // Last Row
        if (!visited[n - 1][i] && board[n - 1][i] == 'O')
        {
            dfs(n - 1, i, visited, board);
        }
    }

    // Traverse the first and the last column
    for (int j = 0; j < n; j++)
    {
        // First Column
        if (!visited[j][0] && board[j][0] == 'O')
        {
            dfs(j, 0, visited, board);
        }

        // Last Column
        if (!visited[j][m - 1] && board[j][m - 1] == 'O')
        {
            dfs(j, m - 1, visited, board);
        }
    }

    // Find remaining O's and mark them as 'X'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // If the cell is O and not visited, it means it is not connected to any edge '0
            if (!visited[i][j] && board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}