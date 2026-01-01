// GFG Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adjList[], vector<int> &visited)
{
    // Mark the start vertex as visited
    visited[src] = 1;

    // Store the current vertex as well as its parent (where its coming from)
    queue<pair<int, int>> q;

    // Its first vertex hence parent is -1
    q.push({src, -1});

    while (!q.empty())
    {
        int vertex = q.front().first;
        int parent = q.front().second;
        q.pop();

        // Traverse all the adjacent vertices
        for (auto it : adjList[vertex])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push({it, vertex});
            }

            // If the vertex is visited but it isn't the parent
            else if (parent != it)
            {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<vector<int>> &edges)
{
    // Create an Adjancency List
    vector<int> adjList[V];

    for (auto &e : edges)
    {
        adjList[e[1]].push_back(e[0]);
        adjList[e[0]].push_back(e[1]);
    }

    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (detect(i, adjList, visited))
            {
                return true;
            }
        }
    }

    return false;
}