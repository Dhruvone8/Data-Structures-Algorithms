// Leetcode Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

bool day_req(vector<int> &weights, int capacity, int days)
{
    int day = 1;
    int loads = 0;
    for(int weight : weights) 
    {
        if(loads + weight > capacity)
        {
            day++;
            loads = weight;
        }
        else
        {
            loads += weight;
        }

        if(day > days)
        {
            return false;
        }
    }

    return true;
}

int shipWithinDays(vector<int>& weights, int days) 
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(day_req(weights, mid, days))
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
