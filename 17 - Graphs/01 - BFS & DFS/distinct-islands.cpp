// Leetcode Link: https://leetcode.com/problems/number-of-distinct-islands-ii/

#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &vec,
                  int baserow, int basecol, int n, int m)
{
    // Mark the land as visited
    visited[row][col] = 1;

    // Store the base co-ordinates so that we can compare two islands
    vec.push_back({row - baserow, col - basecol});

    // Traverse upwards and downwards
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        // Check if the cells are valid
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfsTraversal(nrow, ncol, visited, grid, vec, baserow, basecol, n, m);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // Matrix to mark the cell visited
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // Set to store the distinct lands
    set<vector<pair<int, int>>> st;

    // Traverse the matrix to find the land which is not yet visited
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {

                // Vector to store the co-ordinates of the land
                vector<pair<int, int>> vec;
                dfsTraversal(i, j, visited, grid, vec, i, j, n, m);

                // Insert the vector to the set
                st.insert(vec);
            }
        }
    }

    return st.size();
}