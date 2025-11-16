// GFG Link: https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int> &arr) // Better Solution
{
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int longest = 1;
    int count = 0;
    int lastSmaller = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == lastSmaller)
        {
            count++;
            lastSmaller = arr[i];
        }

        else if (arr[i] != lastSmaller)
        {
            count = 1;
            lastSmaller = arr[i];
        }

        longest = max(longest, count);
    }

    return longest;
}

// Optimal Solution

int longestConsecutiveOpt(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }

    unordered_set<int> hash;
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        hash.insert(arr[i]);
    }

    for (auto el : hash)
    {
        if (hash.find(el - 1) == hash.end()) // First element
        {
            int count = 0;
            int x = el;
            while (hash.find(x + 1) != hash.end())
            {
                x++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

using namespace std;
int main()
{

    return 0;
}