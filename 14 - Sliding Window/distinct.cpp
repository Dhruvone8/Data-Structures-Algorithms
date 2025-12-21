// Leetcode Link: https://leetcode.com/problems/subarrays-with-k-different-integers/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int helper(vector<int> &nums, int k)
{
    int n = nums.size();
    int left = 0;
    int right = 0;
    int count = 0;
    unordered_map<int, int> hash;

    while (right < n)
    {
        hash[nums[right]]++;

        while (hash.size() > k)
        {
            hash[nums[left]]--;
            if (hash[nums[left]] == 0)
            {
                hash.erase(nums[left]);
            }
            left++;
        }

        count += (right - left + 1);
        right++;
    }

    return count;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return helper(nums, k) - helper(nums, k - 1);
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    cout << subarraysWithKDistinct(nums, 2);
    return 0;
}