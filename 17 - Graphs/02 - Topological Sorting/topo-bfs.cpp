#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>> &edges)
{
    // Crate an Adjancency List
    vector<vector<int>> adjList(V);

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
    }

    // Array to store indegree for each vertex
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto &vertex : adjList[i])
        {
            indegree[vertex]++;
        }
    }

    // Queue
    queue<int> q;

    // Push all the vertices with indegree 0 to the queue
    // If the indegree of ant vertex is 0 then it means that no other vertex points to it
    // So these vertices can appear before any other vertices with indegree > 0

    // Find vertex with indegree 0
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;

    // BFS
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto vertex : adjList[node])
        {
            indegree[vertex]--;
            if (indegree[vertex] == 0)
            {
                q.push(vertex);
            }
        }
    }

    return ans;
}