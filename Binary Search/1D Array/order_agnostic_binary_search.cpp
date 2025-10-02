#include <iostream>
#include <vector>
using namespace std;

int order_agnostic_binary_search(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;

    bool isAscending = nums[start] < nums[end];

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (target == nums[mid])
        {
            return mid;
        }

        if (isAscending)
        {
            if (target < nums[mid])
            {
                end = mid - 1;
            }
            else if (target > nums[mid])
            {
                start = mid + 1;
            }
        }
        else
        {
            if (target > nums[mid])
            {
                end = mid - 1;
            }
            else if (target < nums[mid])
            {
                start = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {90, 80, 50, 40, 30, 10};
    int ans = order_agnostic_binary_search(arr, 30);
    cout << ans;
}
