// Leetcode Link: https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    // Create an Adjancency List
    vector<vector<int>> adjList(numCourses);

    for(auto &courses : prerequisites)
    {
        int u = courses[0];
        int v = courses[1];

        adjList[v].push_back(u);
    }

    // Indegree vector
    vector<int> indegree(numCourses, 0);

    for(int i = 0; i < numCourses; i++)
    {
        for(auto course : adjList[i])
        {
            indegree[course]++;
        }
    }

    queue<int> q;

    // Push the course with indegree 0 to the queue
    for(int i = 0; i < numCourses; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty())
    {
        int course = q.front();
        q.pop();

        ans.push_back(course);

        for(auto c : adjList[course])
        {
            indegree[c]--;
            if(indegree[c] == 0)
            {
                q.push(c);
            }
        }
    }

    return ans;
}