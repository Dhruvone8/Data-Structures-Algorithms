// Leetcode Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array?envType=problem-list-v2&envId=array

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = binarySearch(nums, target, true);
        int end = binarySearch(nums, target, false);
        return {start, end};
    }

    int binarySearch(vector<int> &nums, int target, bool findfirstindex)
    {
        int index = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (target < nums[mid])
            {
                end = mid - 1;
            }
            else if (target > nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                index = mid; // Potential Answer Found
                if (findfirstindex)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }
        return index;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {5,7,7,8,8,10};
    vector<int> ans = s.searchRange(arr, 8);
    if (ans[0] != -1)
    {
        cout << "{" << ans[0] << "," << ans[1] << "}" << endl;
    }
    else
    {
        cout << "No valid pair found" << endl;
    }
    return 0;
}