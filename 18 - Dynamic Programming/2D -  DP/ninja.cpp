// GFG Link: https://www.geeksforgeeks.org/problems/geeks-training/1

#include <bits/stdc++.h>
using namespace std;

int maximumPoints(vector<vector<int>> &mat)
{
    int n = mat.size();

    if (n == 1)
        return max({mat[0][0], mat[0][1], mat[0][2]});

    vector<int> prev(4, -1);

    prev[0] = max(mat[0][2], mat[0][1]);
    prev[0] = max(mat[0][0], mat[0][2]);
    prev[0] = max(mat[0][0], mat[0][1]);
    prev[0] = max({mat[0][0], mat[0][1], mat[0][2]});

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, -1);
        
        for (int lastTask = 0; lastTask < 4; lastTask++)
        {
            temp[lastTask] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != lastTask)
                {
                    temp[lastTask] = max(mat[day][task] + prev[task], temp[lastTask]);
                }
            }
        }

        prev = temp;
    }

    return prev[3];
}