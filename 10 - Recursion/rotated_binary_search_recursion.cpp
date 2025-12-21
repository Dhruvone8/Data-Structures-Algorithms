#include <iostream>
#include <vector>
using namespace std;

int RBS(vector<int> &nums, int target, int start, int end)
{
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;

    if (nums[mid] == target)
    {
        return mid;
    }

    if (nums[start] <= nums[mid])
    {
        if (target >= nums[start] && target < nums[mid])
        {
            return RBS(nums, target, start, mid - 1);
        }
        else
        {
            return RBS(nums, target, mid + 1, end);
        }
    }

    if (nums[target] > nums[mid] && nums[target] <= nums[end])
    {
        return RBS(nums, target, mid + 1, end);
    }
    else
    {
        return RBS(nums, target, start, mid - 1);
    }
}

int main()
{
    vector<int> arr = {5, 6, 7, 8, 1, 2, 3};
    cout << RBS(arr, 3, 0, arr.size() - 1);
    return 0;
}