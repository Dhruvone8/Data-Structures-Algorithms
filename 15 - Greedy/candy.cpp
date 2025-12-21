// Leetcode Link: https://leetcode.com/problems/candy/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Slope Approach for optimal solution
int candy(vector<int>& ratings) 
{
    int n = ratings.size();
    int sum = 1;
    int i = 1;

    while(i < n)
    {
        if(ratings[i] == ratings[i - 1])
        {
            sum++;
            i++;
            continue;
        }

        int peak = 1;
        int down = 1;

        while(i < n && ratings[i] > ratings[i - 1])
        {
            peak++;
            sum += peak;
            i++;
        }

        while(i < n && ratings[i] < ratings[i - 1])
        {
            down++;
            sum += down;
            i++;
        }

        if(down > peak)
        {
            sum += (down - peak);
        }
    }

    return sum;
}

int main()
{
    
    return 0;
}