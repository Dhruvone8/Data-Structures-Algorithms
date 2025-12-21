// Leetcode Link: https://leetcode.com/problems/non-overlapping-intervals/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Intuition:
// Pick an interval that ends early to keep more space to fit intervals (Sort by end Time)
// If we pick an interval that ends late, it may block potential smaller intervals that start and end earlier

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    // Sort by end time
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    int count = 1;
    int endTime = intervals[0][1];

    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] >= endTime)
        {
            count++;
            endTime = intervals[i][1];
        }
    }

    return n - count;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals);

    return 0;
}