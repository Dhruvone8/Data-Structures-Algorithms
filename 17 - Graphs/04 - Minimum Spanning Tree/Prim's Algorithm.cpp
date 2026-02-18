// GFG Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> &edges)
{
    // Create Adjancency List
    vector<vector<int>> adjList[V];

    for (auto it : edges)
    {
        adjList[it[0]].push_back({it[1], it[2]});
        adjList[it[1]].push_back({it[0], it[2]});
    }

    // Priority Queue to Store ({Weight, Node})
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to mark nodes as visited
    vector<int> visited(V, 0);

    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // If the node is already visited, continue
        if (visited[node])
            continue;

        visited[node] = 1;
        sum += wt;

        // Traverse the adjancent nodes
        for (auto it : adjList[node])
        {
            int adjNode = it[0];
            int edgeWt = it[1];
            if (!visited[adjNode])
            {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return sum;
}