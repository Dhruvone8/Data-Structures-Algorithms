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

    int count_Rotations(vector<int> &arr)
    {
        int pivot = find_pivot(arr);
        return pivot + 1;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {4, 6, 8, 10, 0, 2};
    cout << "Number of the Rotations in the array is: " << s.count_Rotations(arr);
    return 0;
}