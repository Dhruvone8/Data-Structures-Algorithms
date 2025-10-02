#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void power_set(int index, vector<int> &nums, vector<int> &ans, vector<vector<int>> &result)
{
    if (index == nums.size())
    {
        result.push_back(ans);
        return;
    }

    ans.push_back(nums[index]);
    power_set(index + 1, nums, ans, result);
    ans.pop_back();

    while (index + 1 < nums.size() && nums[index] == nums[index + 1])
    {
        index++;
    }
    power_set(index + 1, nums, ans, result);
}

void power_set_loop(int index, vector<int> &nums, vector<int> &ans, vector<vector<int>> &result) // Without using any base condition
{
    result.push_back(ans);

    for (int i = index; i < nums.size(); i++)
    {
        if (i != index && nums[i] == nums[i - 1])
        {
            continue;
        }
        ans.push_back(nums[i]);
        power_set_loop(i + 1, nums, ans, result);
        ans.pop_back();
    }
}

vector<vector<int>> subsetswithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> ans;
    vector<vector<int>> result;
    power_set(0, nums, ans, result);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = subsetswithDup(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
