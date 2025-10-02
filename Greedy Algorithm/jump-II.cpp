// Leetcode Link: https://leetcode.com/problems/jump-game-ii/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int jump(vector<int>& nums)
{
    int n = nums.size();
    int left = 0;
    int right = 0;
    int jumps_count = 0;

    while(right < n - 1)
    {
        int farthest = 0;
        for(int i = left; i <= right; i++)
        {
            farthest = max(farthest, i + nums[i]);
        }

        left = right + 1;
        right = farthest;
        jumps_count++;
    }

    return jumps_count;
}

int main()
{
    vector<int> nums = {1, 2, 1, 1, 1};

    cout << jump(nums);

    return 0;
}