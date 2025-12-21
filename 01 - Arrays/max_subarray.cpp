#include <iostream>
#include <vector>
using namespace std;

// Not Suitable for large arrays
/*
int maxSubArray(vector<int> &arr)
{
    int n = arr.size();

    int maxSum = INT16_MIN;
    for (int start = 0; start < n; start++)
    {
        int CurrSum = 0;
        for (int end = start; end < n; end++)
        {
            CurrSum += arr[end];
            maxSum = max(CurrSum, maxSum);
        }
    }
    return maxSum;
} 
*/

// Kadane's Algorithm is more optimized
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();

    int MaxSum = INT16_MIN;
    int CurrSum = 0;
    for(int i = 0; i < n; i++)
    {
        CurrSum+=nums[i];
        MaxSum = max(CurrSum, MaxSum);
        if(CurrSum < 0)
        {
            CurrSum = 0;
        }
    }
    return MaxSum;
}

int main()
{
    vector<int> arr = {-1};
    int ans = maxSubArray(arr);
    cout<<ans;
    return 0;
}