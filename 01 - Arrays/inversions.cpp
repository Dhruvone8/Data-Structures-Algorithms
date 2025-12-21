// GFG Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Merge sort approach

int merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp; // Create a temporary array so that original array is not modified
    int left = low;
    int right = mid + 1;
    int count = 0;

    while (left <= mid && right <= high) // If any one of the condition becomes false, the loop breaks
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) // If first array still have some elements left, then add the remaining elements straightaway
    {
        temp.push_back(nums[left]);
        left++;
    }

    while (right <= high) // If second array still have some elements left, then add the remaining elements straightaway
    {
        temp.push_back(nums[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }

    return count;
}

int merge_sort(vector<int> &nums, int low, int high)
{
    int count = 0;
    if (low >= high)
    {
        return count;
    }

    int mid = (low + high) / 2;

    count += merge_sort(nums, low, mid);      // Gives first half
    count += merge_sort(nums, mid + 1, high); // Gives Second Half
    count += merge(nums, low, mid, high);     // Merges them after base condition is reached

    return count;
}

int inversionCount(vector<int> &arr)
{
    return merge_sort(arr, 0, arr.size() - 1);
}