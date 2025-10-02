#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
Question
1. Divide the arrays in k sub-arrays
2. Find the Sum of each sub-array and return the largest sum among them
3. From each of the largest sums, return the smallest one
*/

class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int start;
        int end;

        start = *max_element(nums.begin(), nums.end());
        end = accumulate(nums.begin(), nums.end(), 0);

        while (start < end)
        {
            int mid = (start + end) / 2;

            // Calculate the number of parts we can divide the array in to get the max sum as mid
            int sum = 0;
            int parts = 1;

            for (int num : nums)
            {
                if (sum + num > mid) // It means you have to create a new subarray
                {
                    sum = num;
                    parts++;
                }
                else
                {
                    sum += num;
                }
            }

            if (parts <= k)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start; // Or end
    }
};

int main()
{
    Solution s;
    vector<int> arr = {7, 2, 5, 10, 8};
    int ans = s.splitArray(arr, 2);
    cout << ans;
    return 0;
}