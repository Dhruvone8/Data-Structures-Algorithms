// Leetcode Link: https://leetcode.com/problems/unique-paths-ii/description/

#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> prev(n, 0);

    // If start is blocked
    if (obstacleGrid[0][0] == 1)
        return 0;

    for (int row = 0; row < m; row++)
    {
        vector<int> curr(n, 0);

        for (int col = 0; col < n; col++)
        {
            if (obstacleGrid[row][col] == 1)
                continue;

            if (row == 0 && col == 0)
                curr[col] = 1;
                continue;

            int left = 0;
            int up = 0;

            if (row > 0)
            {
                up = prev[col];
            }

            if (col > 0)
            {
                left = curr[col - 1];
            }

            curr[col] = up + left;
        }

        prev = curr;
    }

    return prev[n - 1];
}