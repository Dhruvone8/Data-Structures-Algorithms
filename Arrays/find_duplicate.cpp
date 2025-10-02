#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;

    while (i < n)
    {
        int correct_index = nums[i] - 1;
        if (nums[i] != nums[correct_index])
        {
            swap(nums[i], nums[correct_index]);
        }
        else
        {
            i++;
        }
    }
    return nums[n-1];
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    int ans = findDuplicate(nums);
    cout << ans;
    return 0;
}