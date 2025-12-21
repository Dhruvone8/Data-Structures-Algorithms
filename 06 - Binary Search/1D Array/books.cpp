// GFG Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool canAllocate(vector<int> &arr, int pages, int students)
{
    int n = arr.size();
    int student_count = 1;
    int student_pages = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] + student_pages <= pages)
        {
            student_pages += arr[i];
        }

        else
        {
            student_count++;
            student_pages = arr[i];
        }

        if(student_count > students)
        {
            return false;
        }
    }

    return true;
}

int findPages(vector<int> &arr, int k)
{
    int n = arr.size();
    if (k > n)
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canAllocate(arr, mid, k))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}