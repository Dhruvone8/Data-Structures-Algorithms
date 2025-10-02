#include <iostream>
#include <vector>
using namespace std;

vector<int> bubble_sort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 1; j < n - i; j++)
        {
            if (nums[j] < nums[j - 1])
            {
                swap(nums[j], nums[j - 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;  
        }
    }
    return nums;
}
int main()
{
    vector<int> nums = {2, 3, 1, 5, 4, 10, 7};
    vector<int> ans = bubble_sort(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}