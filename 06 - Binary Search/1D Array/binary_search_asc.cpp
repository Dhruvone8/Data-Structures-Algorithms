// Use binary search whenever a sorted array is provided -  very ver Very Important

// Assume Array is sorted in ascending order

/*
Algorithm:
1. Find the middle element in the array.
2. The elements in the left side of the middle index are smaller than mid and that on the right are larger than mid.
3. If the target element is equal to the middle element, return mid.
4. If the target element is smaller than the middle element, search in the left partition.
5. If the target element is larger than the middle element, search in the right partition.
*/

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (target < arr[mid])
        {
            end = mid - 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
            return mid;
    }

    return -1;
}

int main()
{
    vector<int> array = {2, 4, 6, 9, 11, 12, 14, 20, 36, 48};
    int ans = binarySearch(array, 14);
    cout << ans;
}