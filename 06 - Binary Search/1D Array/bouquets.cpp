// Leetcode Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<math.h>
using namespace std;

bool isPossible(vector<int>& bloomDay, int day, int m, int k)
{
    long long n = bloomDay.size();
    long long count = 0;
    long long bouquets = 0;
        
    for(int i = 0; i < n; i++)
    {
        if(bloomDay[i] <= day)  // Flower is Bloomed
        {
            count++;
        }

        else    // Flower is not bloomed
        {
            bouquets += count/k;
            count = 0;
        }
    }

    bouquets += count / k;

    if(bouquets >= m)
    {
        return true;
    }

    return false;
}

int minDays(vector<int>& bloomDay, int m, int k) 
{
    long long n = bloomDay.size();
    if((long long) m * k > n)
    {
        return -1;
    } 

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(isPossible(bloomDay, mid, m, k))
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