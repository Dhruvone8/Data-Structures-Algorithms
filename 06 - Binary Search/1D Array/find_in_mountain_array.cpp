// Find the target element in the mountain array, and return the minimum index.

/*
Algorithm:
1. Find Peak element in the Mountain Array.
2. The elements in the left side will be sorted in ascending order and in the right side will be in descending order.
3. Search the target element on the left side using binary search and return its index
4. If not found search in the right side.
*/

// Leetcode Link: https://leetcode.com/problems/find-in-mountain-array?envType=problem-list-v2&envId=array

#include <iostream>
#include <vector>
using namespace std;

class Mountain
{
public:
    int findPeak(vector<int> &arr)
    {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end)
        {
            int mid = (start + end) / 2;

            if (arr[mid] > arr[mid + 1])
            {
                end = mid;
            }
            else if (arr[mid] < arr[mid + 1])
            {
                start = mid + 1;
            }
        }
        return start;
    }

    int order_agnostic_binary_search(vector<int> &arr, int target, int start, int end)
    {
        bool IsAscending = arr[start] < arr[end];

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }

            if (IsAscending)
            {
                if (target < arr[mid])
                {
                    end = mid - 1;
                }
                else if (target > arr[mid])
                {
                    start = mid + 1;
                }
            }

            else
            {
                if (target < arr[mid])
                {
                    start = mid + 1;
                }
                else if (target > arr[mid])
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }

    int search(vector<int> &arr, int target)
    {
        int peak = findPeak(arr);
        int leftSearch = order_agnostic_binary_search(arr, target, 0, peak);

        if (leftSearch != -1)
        {
            return leftSearch;
        }
        else
        {
            int rightSearch = order_agnostic_binary_search(arr, target, peak + 1, arr.size() - 1);
            return rightSearch;
        }
    }
};

int main()
{
    Mountain m;
    vector<int> arr = {1, 2, 3, 7, 3, 2, 1};
    int ans = m.search(arr, 3);
    cout << ans;
    return 0;
}