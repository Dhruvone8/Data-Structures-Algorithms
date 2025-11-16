// Leetcode Link: https://leetcode.com/problems/subarray-sum-equals-k/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();

    // Store sum and its frequency
    unordered_map<int, int> hash;

    // Base Case: Prefix sum = 0 occurs once
    hash[0] = 1;

    int count = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        int rem = sum - k;

        if(hash.find(rem) != hash.end())
        {
            count += hash[rem];
        }

        hash[sum] += 1;
    }

    return count;
}

int main()
{
    vector<int> nums = {3, -3, 1, 1, 1};
    cout << subarraySum(nums, 3);

    return 0;
}