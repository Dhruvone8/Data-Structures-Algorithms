// Leetcode Link: https://leetcode.com/problems/number-of-provinces/description/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjList[], vector<int> visited)
{
    visited[node] = 1;

    for(auto it : adjList[node])
    {
        if(!visited[it])
        {
            dfs(it, adjList, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) 
{
    int n = isConnected.size();

    // Convert Adjancency Matrix to Adjancency List
    vector<int> adjList[n];

    int count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(isConnected[i][j] == 1 && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<int> visited(n, 0);

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(i, adjList, visited);
        }
    }

    return count;
}