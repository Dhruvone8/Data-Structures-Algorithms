// Leetcode Link: https://leetcode.com/problems/maximum-product-subarray/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int prefix = 1;
    int suffix = 1;
    int maxPro = INT16_MIN;

    for(int i = 0; i < nums.size(); i++)
    {
        if(prefix == 0)
        {
            prefix = 1;
        }

        if(suffix == 0)
        {
            suffix = 1;
        }

        prefix = prefix * nums[i];
        suffix = suffix * nums[n - 1 - i];

        maxPro = max(maxPro, max(prefix, suffix));
    }

    return maxPro;
}

int main()
{
    vector<int> nums = {2, 3, -2, 4};

    cout << maxProduct(nums);

    return 0;
}