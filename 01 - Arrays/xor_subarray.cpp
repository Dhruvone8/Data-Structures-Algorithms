// GFG Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

long subarrayXor(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> hash; // To keep track of previous XOR Values and its count
    hash[0]++;                    // Insert {0, 1} inside the map
    int xr = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];

        int x = xr ^ k;

        count += hash[x];

        hash[xr]++;
    }

    return count;
}