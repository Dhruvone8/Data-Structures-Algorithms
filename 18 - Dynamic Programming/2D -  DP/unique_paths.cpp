// Leetcode Link: https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<int> prev(n, 0);

        for (int row = 0; row < m; row++)
        {
            vector<int> curr(n, 0);
            for (int col = 0; col < n; col++)
            {
                if (row == 0 && col == 0)
                {
                    curr[col] = 1;
                }

                else
                {
                    int up = 0;
                    int left = 0;
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
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};