// GFG Link: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
// Leetcode Link: https://leetcode.com/problems/split-array-largest-sum/

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool isPossible(vector<int> nums, int sum, int k)
{
    int n = nums.size();
    int subsum = 0;
    int subcount = 1;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] + subsum <= sum)
        {
            subsum += nums[i];
        }
        
        else
        {
            subcount++;
            subsum = nums[i];
        }

        if(subcount > k)
        {
            return false;
        }

        return true;
    }
}

int splitArray(vector<int>& nums, int k) 
{
    int n = nums.size();
    if (k > n)
    {
        return -1;
    }

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(nums, mid, k))
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

int main()
{
    
    return 0;
}