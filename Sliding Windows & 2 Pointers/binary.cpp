// Leetcode Link: https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count(vector<int> &nums, int goal)
{
    int n = nums.size();
    int right = 0;
    int left = 0;
    int count = 0;
    int sum = 0;

    while (right < n)
    {
        if (goal < 0)
        {
            return 0;
        }

        sum += nums[right];

        while (sum > goal)
        {
            sum = sum - nums[left];
            left++;
        }

        count = count + (right - left + 1);
        right++;
    }

    return count;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int s1 = count(nums, goal);
    int s2 = count(nums, goal - 1);

    return s1 - s2;
}

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    cout << numSubarraysWithSum(nums, 2);
    return 0;
}