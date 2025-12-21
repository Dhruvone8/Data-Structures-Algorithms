#include <iostream>
#include <vector>
using namespace std;

vector<int> running_sum(vector<int> &nums)
{
    vector<int> sums(nums.size());
    sums[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        sums[i] = sums[i - 1] + nums[i];
    }
    return sums;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = running_sum(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}