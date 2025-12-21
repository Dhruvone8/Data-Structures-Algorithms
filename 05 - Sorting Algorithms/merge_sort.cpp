/*
Steps:
1. Divide the array into two parts
2. Sort the parts via recursion
3. Merge the sorted parts
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp; // Create a temporary array so that original array is not modified
    int left = low;
    int right = mid + 1;

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
}

void merge_sort(vector<int> &nums, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;

    merge_sort(nums, low, mid);      // Gives first half
    merge_sort(nums, mid + 1, high); // Gives Second Half
    merge(nums, low, mid, high);     // Merges them after base condition is reached
}

int main()
{
    vector<int> arr = {5, 4, 2, 1, 3};
    merge_sort(arr, 0, arr.size() - 1);
    for (int num : arr)
    {
        cout << num << " ";
    }
    return 0;
}

/*
Time Complexity : O(n * log(n))
Space Complexity : O(n)
*/