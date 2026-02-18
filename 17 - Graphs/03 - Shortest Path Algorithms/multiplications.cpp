// GFG Link: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    if (start == end)
        return 0;

    auto const mod = 100000;
    int n = arr.size();

    // Queue
    queue<pair<int, int>> q;

    vector<int> steps(100000, 1e9);

    q.push({start, 0});
    steps[start] = 0;

    while (!q.empty())
    {
        int num = q.front().first;
        int step = q.front().second;
        q.pop();

        for (int i = 0; i < n; i++)
        {
            int nextnum = (arr[i] * num) % mod;
            if (step + 1 < steps[nextnum])
            {
                steps[nextnum] = step + 1;
                if (nextnum == end)
                    return step + 1;
                q.push({nextnum, step + 1});
            }
        }
    }

    return -1;
}
