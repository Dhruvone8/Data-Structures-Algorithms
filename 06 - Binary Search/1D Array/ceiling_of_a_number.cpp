// Ceiling of a number: Smallest Element in the array that is greater or equal to the target elemenmt

#include <iostream>
#include <vector>
using namespace std;

int ceiling_element(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;

    if (target > arr[arr.size() - 1])
    {
        return -1;
    }

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
            return arr[mid];
        }
    }
    return arr[start];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 7, 8, 10};
    int ans = ceiling_element(arr, 9);
    cout << ans;
}