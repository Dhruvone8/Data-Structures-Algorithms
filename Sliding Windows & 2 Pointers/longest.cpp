// GFG Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int longestSubarrayI(vector<int>& arr, int k) // Optimal if array has zeroes and positive value only
{
    int n = arr.size();
    int left = 0;
    int right = 0;
    int maxlen = 0;
    long long sum = arr[0];

    while(right < n)
    {
        if(sum > k)
        {
            while(sum > k && left <= right)
            {
                sum -= arr[left];
                left++;
            }
        }
    
        if(sum == k)
        {
            maxlen = max((right - left + 1), maxlen);
        }

        right++;
        if(right < n)
        {
            sum += arr[right];
        }
    }

    return maxlen;
}

int longestSubarray(vector<int>& arr, int k) // Optimal for both negative as well as positive values
{
    int n = arr.size();
    int sum = 0;
    int maxlen = 0;

    // Store the prefix Sum in the hash map with index
    unordered_map<int, int> hash;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == k)
        {
            maxlen = max(maxlen, i + 1);
        }

        int rem = sum - k;
        if(hash.find(rem) != hash.end())
        {
            int len = i - hash[rem];
            maxlen = max(len, maxlen);
        }

        if(hash.find(sum) == hash.end())
        {
            hash[sum] = i;
        }
    }

    return maxlen;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};

    cout << longestSubarray(arr, 3);

    return 0;
}