#include <iostream>
#include <vector>
using namespace std;

vector<int> rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> new_array(n, 0);

    for (int i = 0; i < n; i++)
    {
        new_array[(i + k) % n] = nums[i];
    }
    return new_array;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> ans = rotate(nums, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}