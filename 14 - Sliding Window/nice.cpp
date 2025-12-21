// Leetcode Link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count_odd(vector<int> &nums, int k)
{
    int n = nums.size();
    int left = 0;
    int right = 0;
    int odd_count = 0;
    int count = 0;

    while (right < n)
    {
        if (k < 0)
        {
            return 0;
        }

        if (nums[right] % 2 != 0)
        {
            odd_count++;
        }

        while (odd_count > k)
        {
            if(nums[left] % 2 != 0)
            {
                odd_count--;
            }

            left++;
        }

        count = count + (right - left + 1);
        right++;
    }

    return count;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    return count_odd(nums, k) - count_odd(nums, k - 1);
}

int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    cout << numberOfSubarrays(nums, 3);
    return 0;
}