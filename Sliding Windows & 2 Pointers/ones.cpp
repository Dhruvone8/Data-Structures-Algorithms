// Leetcode Link: https://leetcode.com/problems/max-consecutive-ones-iii/

/*
Approach:
Find the longest subarray with max zeroes as k
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int left = 0;
    int right = 0;
    int maxlength = 0;
    int length = 0;
    int zeroes = 0;

    while (right < n)
    {
        if (nums[right] == 0)
        {
            zeroes++;
        }

        while (zeroes > k)
        {
            if (nums[left] == 0)
            {
                zeroes--;
            }

            left++;
        }

        if(zeroes <= k)
        {
            length = right - left + 1;
            maxlength = max(maxlength, length);
        }

        right++;
    }

    return maxlength;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << longestOnes(nums, 3);

    return 0;
}