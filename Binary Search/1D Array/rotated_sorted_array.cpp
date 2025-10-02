/*
Algorithm:
1. Find the Peak element (4 Cases)
2. Elements in the left and right side of the peak element are in ascending order, so apply Binary Search to find target
*/

// Leetcode Link: https://leetcode.com/problems/search-in-rotated-sorted-array?envType=problem-list-v2&envId=array

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
    public:
        int find_pivot(vector<int> &arr)
        {
            int start = 0;
            int end = arr.size() - 1;

            while (start <= end)
            {
                int mid = (start + end) / 2;

                if (mid < end && arr[mid] > arr[mid + 1])
                {
                    return mid;
                }
                else if (mid > start && arr[mid] < arr[mid - 1])
                {
                    return mid - 1;
                }
                else if (arr[mid] < arr[start])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            return -1;
        }

        int binary_search(vector<int> &arr, int target, int start, int end)
        {
            while (start <= end)
            {
                int mid = (start + end) / 2;

                if (target > arr[mid])
                {
                    start = mid + 1;
                }
                else if (target < arr[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    return mid;
                }
            }
            return -1;
        }

        int search(vector<int> &nums, int target)
        {
            int pivot = find_pivot(nums);

            if (pivot == -1)
            {
                return binary_search(nums, target, 0, nums.size() - 1);
            }
            else
            {
                if (target == nums[pivot])
                {
                    return pivot;
                }
                else if (target >= nums[0])
                {
                    return binary_search(nums, target, 0, pivot - 1);
                }
                else
                {
                    return binary_search(nums, target, pivot + 1, nums.size() - 1);
                }
            }
            return -1;
        }
};

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    Solution s;
    int ans = s.search(arr, 6);
    cout << ans;
}