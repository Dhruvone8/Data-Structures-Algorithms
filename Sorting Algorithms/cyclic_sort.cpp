// When Numbers are given from 1 to n, use Cyclic Sort - Very Very Very Very Very Important

#include <iostream>
#include <vector>
using namespace std;

vector<int> cyclic_sort(vector<int> &nums)
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
    return nums;
}

int main()
{
    vector<int> nums = {4, 5, 2, 1, 3};
    vector<int> ans = cyclic_sort(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}