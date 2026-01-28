// Leetcode LinK: https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        // Queue (Stores {row, col})
        queue<pair<int, int>> q;

        // Distance Matrix
        vector<vector<int>> dist(n, vector<int>(n, -1));

        dist[0][0] = 1;
        q.push({0, 0});

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row == n - 1 && col == n - 1)
                return dist[row][col];

            // Traverse the eight directions
            for (int i = 0; i < 8; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && dist[nrow][ncol] == -1) {
                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return -1;
    }
};