// GFG Link: https://www.geeksforgeeks.org/problems/geek-jump/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &height)
    {
        // Represent Problem in terms of index
        // Do All stuffs on the index
        // Take Minimal of all stuff
        int n = height.size();

        if (n == 0)
            return 0;

        int prev1 = 0;
        int prev2 = 0;
        int curr;
     
        for (int i = 1; i < n; i++)
        {
            int left = prev1 + abs(height[i] - height[i - 1]);
            int right = INT_MAX;
            if (i > 1)
            {
                right = prev2 + abs(height[i] - height[i - 2]);
            }
            
            curr = min(left, right);
            prev2 = prev1;
            prev1 = curr;
            
        }

        return prev1;
    }
};