// Leetcode Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool divsum(vector<int> &nums, int divisor, int threshold)
{
    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)nums[i] / divisor);
        if(sum > threshold)
        {
            return false;
        }
    }

    return true;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (divsum(nums, mid, threshold)) // Divisor is large, can try for better
        {
            high = mid - 1;
        }

        else    // Divisor is too large
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    vector<int> nums= {1, 2, 5, 9};
    cout << smallestDivisor(nums, 6);

    return 0;
}