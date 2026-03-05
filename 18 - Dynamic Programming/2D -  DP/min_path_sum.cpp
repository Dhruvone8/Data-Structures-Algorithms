// Leetcode Link: https://leetcode.com/problems/minimum-path-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);

        for (int row = 0; row < m; row++) {

            vector<int> curr(n, 0);

            for (int col = 0; col < n; col++) {

                if (row == 0 && col == 0) {
                    curr[col] = grid[row][col];
                }
                else {
                    int up = 1e9;
                    int left = 1e9;

                    if (row > 0)
                        up = grid[row][col] + prev[col];

                    if (col > 0)
                        left = grid[row][col] + curr[col - 1];

                    curr[col] = min(up, left);
                }
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};