// GFG Link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Time Complexity: O(2N)
// Space Complexity: O(N)
vector<int> findTwoElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;

    sort(arr.begin(), arr.end());
    vector<int> hash(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        hash[i]++;
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (hash[i] == 0)
        {
            ans.push_back(i);
        }

        if (hash[i] == 2)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

// Optimal Solution

// Sum up all the elements present in the array
// Sum up all the elements from 1 to N
// Take Difference of both and keep it as equation - 1

// Sum up the squares of all the elements present in the array
// Sum up the squares of all elements from 1 to N
// Take Difference of both and keep it as equation - 2

// Add both equations and find the final values

// Time Complexity: O(N)
// Space Complexity: O(1)
vector<int> findTwoElementOpt(vector<int> &arr)
{
    long long n = arr.size();

    long long nsum = (n * (n + 1)) / 2;

    long long nsumsq = (n * (n + 1) * (2 * n + 1)) / 6;

    long long arrsum = 0;
    long long arrsumsq = 0;

    for (int i = 0; i < n; i++)
    {
        arrsum += arr[i];
        arrsumsq += (long long)arr[i] * (long long)arr[i];
    }

    long long diff = arrsum - nsum;
    long long diffsq = arrsumsq - nsumsq;
    diffsq = diffsq / diff;

    long long rep = (diffsq + diff) / 2;
    long long mis = rep - diff;

    return {(int)rep, (int)mis};
}