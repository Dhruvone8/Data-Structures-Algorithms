// Assume a infinte sorted array i.e use of size method is prohibhited

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int target, int start, int end)
{
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

int infiniteArray(vector<int> &arr, int target)
{
    // First find the range of the array
    int start = 0;
    int end = 1;
    // Double the range at each step. Following reverse Binary Search Algorithm

    while (target >= arr[end])
    {
        int newstart = end + 1;
        end = end + 2 * (end - start + 1); // end = previous end +  2*(box_size)
        start = newstart;
    }
    return binarySearch(arr, target, start, end);
}

int main()
{
    vector<int> arr = {2, 4, 5, 6, 7, 8, 9, 10};
    int ans = infiniteArray(arr, 10);
    cout << ans;
}
