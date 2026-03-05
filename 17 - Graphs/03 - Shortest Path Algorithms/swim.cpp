// Leetcode Link: https://leetcode.com/problems/swim-in-rising-water/description/

#include <bits/stdc++.h>
using namespace std;

int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();

    // Priority Queue stores ({Elevation, {row, col}})
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    // Matrix to mark cell as visited
    vector<vector<int>> visited(n, vector<int>(n, 0));

    // Mark the starting node visited
    visited[0][0] = 1;

    // Push starting node to the priority queue
    pq.push({grid[0][0], {0, 0}});

    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, -1, 0, 1};

    while (!pq.empty())
    {
        int elevation = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;

        // If destination is reached, return elevation
        if (row == n - 1 && col == n - 1)
            return elevation;

        // Traverse neighboring cells
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            // Check for bounds
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n)
            {
                // Check if not visited
                if(!visited[nrow][ncol])
                {
                    visited[nrow][ncol] = 1;
                    pq.push({max(elevation, grid[nrow][ncol]), {nrow, ncol}});
                }
            }
        }
    }

    return -1;
}
