// Leetcode Link: https://leetcode.com/problems/assign-cookies/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int m = g.size();
    int n = s.size();

    sort(s.begin(), s.end());
    sort(g.begin(), g.end());

    int first = 0;
    int second = 0;

    while (first < m && second < n)
    {
        if (s[second] >= g[first])
        {
            first++;
        }

        second++;
    }

    return first;
}

int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << findContentChildren(g, s);
    return 0;
}