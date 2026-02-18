// Leetcode Link: https://leetcode.com/problems/container-with-most-water/description/

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size();

    int left = 0;
    int right = n - 1;

    int maxarea = 0;
    while (left < right)
    {
        int area = min(height[left], height[right]) * (right - left);
        maxarea = max(area, maxarea);

        if(height[left] > height[right])
        {
            right--;
        }

        else
        {
            left++;
        }
    }

    return maxarea;
}