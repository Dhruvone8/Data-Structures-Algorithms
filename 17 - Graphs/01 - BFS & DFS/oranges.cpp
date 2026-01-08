// https://leetcode.com/problems/rotting-oranges/

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // Matrix to mark the rotten oranges
    vector<vector<int>> rotten(n, vector<int>(m));

    // Store (row, col) and time inside the queue {{row, col}, time}

    queue<pair<pair<int, int>, int>> q;

    // Traverse the grid and find all rotten oranges initially present
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                // Push them into queue and mark as rotten
                q.push({{i, j}, 0});
                rotten[i][j] = 2;
            }
        }
    }

    // After getting all rotten oranges, do bfs traversal to rot neighbor oranges
    int time = 0;
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        time = max(t, time);
        q.pop();

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && rotten[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, time + 1});
                rotten[nrow][ncol] = 2;
            }
        }
    }

    // Check if all fresh oranges are rotten
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(rotten[i][j] != 2 && grid[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return time;
}