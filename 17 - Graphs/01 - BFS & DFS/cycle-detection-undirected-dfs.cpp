#include <bits/stdc++.h>
using namespace std;

bool dfs(int vertex, int parent, vector<int> adjList[], vector<int> &visited)
{
    visited[vertex] = 1;

    for (auto it : adjList[vertex])
    {
        if (!visited[it])
        {
            if (dfs(it, vertex, adjList, visited) == true)
                return true;
        }
        else if (visited[it] && it != parent)
            return true;
    }

    return false;
}

bool isCycle(int V, vector<vector<int>> &edges)
{
    // Create an adjancency list
    vector<int> adjList[V];

    for (auto &el : edges)
    {
        adjList[el[0]].push_back(el[1]);
        adjList[el[1]].push_back(el[0]);
    }

    // Array to mark visited vertices
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adjList, visited))
                return true;
        }
    }

    return false;
}