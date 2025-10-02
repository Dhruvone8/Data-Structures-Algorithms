#include <iostream>
#include <vector>
using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> array(2 * n);

    for (int i = 0; i < n; i++)
    {
        array[2 * i] = nums[i];
        array[2 * i + 1] = nums[i + n];
    }
    return array;
}

int main()
{
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    vector<int> ans = shuffle(nums, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
