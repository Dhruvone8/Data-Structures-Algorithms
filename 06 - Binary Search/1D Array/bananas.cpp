// Leetcode Link: https://leetcode.com/problems/koko-eating-bananas/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;

int helper(vector<int> &piles, int hourly_rate)
{
    long long total_hours = 0;
    for (int pile : piles)
    {
        total_hours += ceil((double)pile / (double)hourly_rate);
    }

    return total_hours;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalhours = helper(piles, mid);
        if (totalhours <= h)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{

    return 0;
}