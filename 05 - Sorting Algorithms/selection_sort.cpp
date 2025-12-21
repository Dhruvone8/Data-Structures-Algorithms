#include <iostream>
#include <vector>
using namespace std;

vector<int> selection_sort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[min_index])
            {
                min_index = j;
            }
        }
        swap(nums[min_index], nums[i]);
    }
    return nums;
}

int main()
{
    vector<int> nums = {5, 3, 1, 4, 2, 10, 6, 8, 9, 7};
    vector<int> ans = selection_sort(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}