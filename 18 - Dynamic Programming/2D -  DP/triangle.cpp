// Leetcode Link: https://leetcode.com/problems/triangle/description/

#include <bits/stdc++.h>
using namespace std;

// Variable Ending Point
// There can be multiple recurrence because the ending point is variable so we try out each point from bottom to up
// Recursion will be made by starting from all the columns in the last row
// Therefore to avoid it, start from the end which is fixed
// Start recursion from (0, 0)

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> front(n, 0);

    // Base Case
    for (int i = 0; i < n; i++)
    {
        front[i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(n, 0);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];

            curr[j] = min(down, diagonal);
        }

        front = curr;
    }

    return front[0];
}