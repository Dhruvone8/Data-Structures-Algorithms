/*
Pick a random element from the array(pivot)
Place the elements smaller than pivot to the left side of the pivot
Place the elements greater than pivot to the right side of the pivot
The array will be sorted eventually
*/

#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> &nums, int low, int high)
{
    if (low > high)
    {
        return;
    }

    int start = low;
    int end = high;
    int mid = (start + end) / 2;
    int pivot = nums[mid];

    while (start <= end)
    {
        while (nums[start] < pivot)
        {
            start++;
        }

        while (nums[end] > pivot)
        {
            end--;
        }

        if (start <= end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    // Now Pivot is at correct index so sort the two halves of the array using recursion
    quick_sort(nums, low, end);
    quick_sort(nums, start, high);
}

int main()
{
    vector<int> arr = {5, 3, 4, 1, 2, 7, 9, 10, 6, 8};
    quick_sort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
Time Complexity : O(n * log(n))
Space Complexity : O(1)
*/