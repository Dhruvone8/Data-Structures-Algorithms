#include <iostream>
#include <vector>
using namespace std;

vector<int> insertion_sort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (nums[j - 1] > nums[j])
            {
                swap(nums[j - 1], nums[j]);
            }
            else
            {
                break;
            }
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {4, 3, 5, 2, 1, 8, 9, 6, 10, 7};
    vector<int> ans = insertion_sort(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}