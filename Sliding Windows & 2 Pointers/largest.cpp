// GFG Link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int maxLength(vector<int>& arr) 
{
    int n = arr.size();
    int sum = 0;
    int maxlen = 0;

    // Store the prefix Sum in the hash map with index
    unordered_map<int, int> hash;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == 0)
        {
            maxlen = max(maxlen, i + 1);
        }

        int rem = sum;
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