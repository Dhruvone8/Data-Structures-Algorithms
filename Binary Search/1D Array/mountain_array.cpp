#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end)
        {
            int mid = (start + end) / 2;

            if (arr[mid] < arr[mid + 1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return start; // or return end, both start and end points to the same element
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5, 2, 1};
    int ans = s.peakIndexInMountainArray(arr);
    cout << ans << endl;
    vector<int> nums = {5, 10, 15, 20, 19, 18, 15};
    int ans2 = s.peakIndexInMountainArray(nums);
    cout << ans2 << endl;
}
