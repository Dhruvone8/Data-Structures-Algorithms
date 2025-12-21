#include <iostream>
#include <vector>
using namespace std;

void power_set(int index, vector<int> &nums, vector<int> &ans)
{
    if (index == nums.size())
    {
        for (auto val : ans)
        {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    ans.push_back(nums[index]);
    power_set(index + 1, nums, ans);

    ans.pop_back();
    power_set(index + 1, nums, ans);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> ans = {};
    power_set(0, nums, ans);
    return 0;
}