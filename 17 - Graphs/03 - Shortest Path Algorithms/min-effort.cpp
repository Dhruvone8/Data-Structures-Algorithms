// Leetcode Link: https://leetcode.com/problems/path-with-minimum-effort/description/

#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>> &heights)
{
    // To Find the minimum of all the maximum absoulte difference
    int n = heights.size();
    int m = heights[0].size();

    // Matrix to track maximum absolute difference
    vector<vector<int>> mad(n, vector<int>(m, 1e9));

    // Min Heap to Store {difference, {row, col}}
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                          greater<pair<int, pair<int, int>>>>
        pq;

    mad[0][0] = 0;
    pq.push({0, {0, 0}});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};

    while (!pq.empty())
    {
        int diff = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if (row == n - 1 && col == m - 1)
        {
            return diff;
        }

        // Traverse four directions
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            // Check if the cells are valid
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]), diff);
                if (newEffort < mad[nrow][ncol])
                {
                    mad[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
            }
        }
    }

    return 0;
}