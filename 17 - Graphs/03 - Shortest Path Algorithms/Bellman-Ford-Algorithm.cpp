// Bellman Ford Algorithm Works only for Directed Graphs

#include <bits/stdc++.h>
using namespace std;

// Approach:
// Relax all the edges N - 1 times
// If the distance still gets reduced on Nth iteration, negative cycle is detected

// Time Complexity = O(V * E)

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    // Vector to track distance
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    // Relax N - 1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Relax Nth time to detect negative cycle
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }

    return dist;
}