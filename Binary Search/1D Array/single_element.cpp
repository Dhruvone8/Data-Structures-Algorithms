#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // Check if mid is the single element
        if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
            (mid == n - 1 || nums[mid] != nums[mid + 1]))
        {
            return nums[mid]; 
        }

        int leftsize;
        if (mid > 0 && nums[mid] == nums[mid - 1])
        {
            leftsize = mid - 1;
        }
        else
        {
            leftsize = mid;
        }

        if (leftsize % 2 == 0)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    int ans = singleNonDuplicate(nums);
    cout << ans;
}