// GFG Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Jobs
{
    int id;
    int dead;
    int pro;
};

class Solution
{
public:
    bool static comp(Jobs a, Jobs b)
    {
        return a.pro > b.pro;
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        int n = deadline.size();
        vector<Jobs> jobs(n);

        for (int i = 0; i < n; i++)
        {
            jobs[i] = {i + 1, deadline[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), comp);

        int maxDeadline = 0;
        for (auto &job : jobs)
        {
            maxDeadline = max(maxDeadline, job.dead);
        }

        vector<int> slots(maxDeadline + 1, -1);
        int totalProfit = 0;
        int countJobs = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = jobs[i].dead; j >= 0; j--)
            {
                if(slots[j] == -1)
                {
                    countJobs++;
                    slots[i] = jobs[j].id;
                    totalProfit += jobs[i].pro;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};

int main()
{

    return 0;
}