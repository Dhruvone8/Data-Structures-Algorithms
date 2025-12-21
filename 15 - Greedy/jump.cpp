// Leetcode Link: https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int max_index = 0;

    for (int i = 0; i < n; i++)
    {
        if (i > max_index)
        {
            return false;
        }

        max_index = max(max_index, i + nums[i]);

        if (max_index >= n - 1)
        {
            break;
        }
    }

    return true;
}

int main()
{
    vector<int> nums = {2, 3, 1, 0, 2};

    cout << canJump(nums);

    return 0;
}