// Assume Array is sorted in ascending order

#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (target > nums[mid])
        {
            end = mid - 1;
        }
        else if (target < nums[mid])
        {
            start = start + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int ans = binarysearch(arr, 70);
    cout<<ans;
}