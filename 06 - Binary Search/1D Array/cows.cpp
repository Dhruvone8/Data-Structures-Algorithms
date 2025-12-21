// GFG Link: https://www.geeksforgeeks.org/problems/aggressive-cows/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPlaced(vector<int> &stalls, int distance, int cows)
{
    int n = stalls.size();
    int count = 1;
    int last_pos = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last_pos >= distance)
        {
            count++;
            last_pos = stalls[i];
        }
        
        if(count == cows)
        {
            return true;
        }
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int max_el = *max_element(stalls.begin(), stalls.end());
    int min_el = *min_element(stalls.begin(), stalls.end());

    int high = max_el - min_el;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(isPlaced(stalls, mid, k))
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return high;
}