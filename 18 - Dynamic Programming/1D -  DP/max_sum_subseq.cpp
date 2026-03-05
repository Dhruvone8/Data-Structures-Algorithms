// GFG Link: https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, -1);

        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++)
        {

            int pick = arr[i] + dp[i - 2];

            int notPick = 0 + dp[i - 1];

            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }
};