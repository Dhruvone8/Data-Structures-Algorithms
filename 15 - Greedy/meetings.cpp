// GFG Link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// Greedy Approach: Pick those meetings that end faster
// Sort by end time

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meet
{
    int start;
    int end;
};

class Solution
{
public:
    bool static comp(Meet a, Meet b) //  Create a custom comparator
    {
        return a.end < b.end;
    }

    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int n = start.size();
        vector<Meet> meet(n);

        for(int i = 0; i < n; i++)
        {
            meet[i] = {start[i], end[i]};
        }

        sort(meet.begin(), meet.end(), comp);

        int count = 1;
        int freetime = meet[0].end;

        for(int i = 0; i < n; i++)
        {
            if(meet[i].start > freetime)
            {
                count++;
                freetime = meet[i].end;
            }
        }

        return count;
    }
};