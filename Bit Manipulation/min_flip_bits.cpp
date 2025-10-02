// Return the minimum bits needed to flip to convert a number into another

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Brute Force Approach

/*
int minBitFlips(int start, int goal)
{
    // Convert start and goal into its binary form
    string binStart = "";
    string binGoal = "";

    while(start != 0)
    {
        if(start % 2 == 0)
        {
            binStart += '0';
        }
        else
        {
            binStart += '1';
        }

        start = start / 2;
    }

    while(goal != 0)
    {
        if(goal % 2 == 0)
        {
            binGoal += '0';
        }
        else
        {
            binGoal += '1';
        }

        goal = goal / 2;
    }

    reverse(binStart.begin(), binStart.end());
    reverse(binGoal.begin(), binGoal.end());


    int count = 0;

    int n = binStart.size();
    int m = binGoal.size();
    int diff = abs(n - m);

    if(n > m)
    {
        for(int i = diff; i > 0; i--)
        {
            binGoal.insert(0, "0");
        }
    }

    if(m > n)
    {
        for(int i = diff; i > 0; i--)
        {
            binStart.insert(0, "0");
        }
    }

    for(int i = 0; i < binStart.size(); i++)
    {
        if(binStart[i] != binGoal[i])
        {
            binGoal[i] = ~binGoal[i];
            count++;
        }
    }

    return count;
}
*/

int minBitFlips(int start, int goal)
{
    int ans = start ^ goal;

    int count = 0;
    while(ans != 0)
    {
        ans = ans & ans - 1;
        count++;
    }

    return count;
}

int main()
{
    cout << minBitFlips(4, 3);
    return 0;
}