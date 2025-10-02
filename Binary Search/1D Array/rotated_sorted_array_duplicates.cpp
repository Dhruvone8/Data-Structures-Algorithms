#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int find_pivot_with_duplicates(vector<int> &arr)
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

            if (arr[mid] == arr[start] && arr[mid] == arr[end])
            {
                // Check if start is the pivot
                if (arr[start] > arr[start + 1])
                {
                    return start;
                }
                start++;

                // Check if end is the pivot
                if (arr[end-1] > arr[end])
                {
                    return end-1;
                }
                end--;  
            }

            // If left side is sorted then pivot must be in right
            else if(arr[start] < arr[mid] || (arr[start] == arr[mid] && arr[end] < arr[mid]))
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }

        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {2,2,3,9,2,2};
    int ans = s.find_pivot_with_duplicates(arr);
    cout<<ans;
}