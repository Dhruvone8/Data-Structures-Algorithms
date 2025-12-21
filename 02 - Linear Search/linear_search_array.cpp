#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    if (size == 0)
    {
        cout << "Array is empty" << endl;
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return the index where the element is found
        }
    }
    return -1; // If element not found
}

int linearSearchMin(int arr[], int size)
{

    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int nums[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(nums) / sizeof(nums[0]); // Calculate array size
    int target = 70;
    int result = linearSearch(nums, size, target);
    if (result != -1)
    {
        cout << "Target element found at index " << result << endl;
    }
    else
    {
        cout << "Target Element not found! " << endl;
    }

    int minimum = linearSearchMin(nums, size);
    cout << "Smallest Number in the array is " << minimum;

    return 0;
}