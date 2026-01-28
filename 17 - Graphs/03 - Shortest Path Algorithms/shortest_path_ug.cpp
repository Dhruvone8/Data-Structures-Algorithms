// GFG Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, vector<vector<int>> &edges, int src)
{
    // Number of edges
    int n = edges.size();

    // Create Adjancency List
    vector<vector<int>> adjList(n);

    for (auto &vec : edges)
    {
        int u = vec[0];
        int v = vec[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Vector to keep track of distances
    vector<int> distance(V, -1);

    // Queue to store the distance as well the node
    queue<pair<int, int>> q;

    // Push the src node as distance 0 to the queue
    q.push({src, 0});

    distance[src] = 0;

    while (!q.empty())
    {
        int node = q.front().first;
        int dist = q.front().second;

        // Traverse the adjList for the node
        for (auto &vec : adjList[node])
        {
            q.push({vec, dist + 1});
            if (distance[vec] == -1)
            {
                distance[vec] = dist + 1;
            }
        }
    }

    return distance;
}