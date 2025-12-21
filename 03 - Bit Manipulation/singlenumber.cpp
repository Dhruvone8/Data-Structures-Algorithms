#include<iostream>
#include<vector>
using namespace std;

int single_number(vector<int> &nums)
{
    int n = nums.size() - 1;
    int ans = nums[0];

    for(int i = 0; i < n; i++)
    {
        ans = ans ^ nums[i+1];
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,2,1};
    int ans = single_number(nums);
    cout<<ans;
}