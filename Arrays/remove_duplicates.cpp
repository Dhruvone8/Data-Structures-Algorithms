#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();

    int num = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[num] = nums[i];
            num++;
        }
        else
        {
            continue;
        }
    }
    return num;
}

int main()
{
    vector<int> nums = {0, 0, 1, 2, 2, 3, 3};
    int ans = removeDuplicates(nums);
    cout << ans;
    return 0;
}