#include<iostream>
#include<vector>
using namespace std;

vector<int> cyclic_sort(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();

    while(i < n)
    {
        int correct_index = nums[i];
        if(correct_index < n && nums[i] != nums[correct_index])
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

int missingNumber(vector<int>& nums)
{
    vector<int> arr = cyclic_sort(nums);
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] != i)
        {
            return i;
        }
    }
    return arr.size();
}

int main()
{
    vector<int> nums = {5, 2, 1, 3, 0};
    int ans = missingNumber(nums);
    cout<<ans;
    return 0;
}