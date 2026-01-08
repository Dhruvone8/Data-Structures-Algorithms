// Leetcode Link: https://leetcode.com/problems/number-of-enclaves/

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid)
{
    visited[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dr[i];
        int ncol = col + dc[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, visited, grid);
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    // Find the boundary 1's

    // First and Last Row
    for (int i = 0; i < m; i++)
    {
        // First Row
        if (!visited[0][i] && grid[0][i] == 1)
        {
            dfs(0, i, visited, grid);
        }

        // Last Row
        if (!visited[n - 1][i] && grid[n - 1][i] == 1)
        {
            dfs(n - 1, i, visited, grid);
        }
    }

    // First and Last Column
    for (int i = 0; i < n; i++)
    {
        // First Column
        if (!visited[i][0] && grid[i][0] == 1)
        {
            dfs(i, 0, visited, grid);
        }

        // First Column
        if (!visited[i][m - 1] && grid[i][m - 1] == 1)
        {
            dfs(i, m - 1, visited, grid);
        }
    }
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                count++;
            }
        }
    }

    return count;
}