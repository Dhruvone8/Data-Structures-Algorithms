// GFG Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Dijkstra's Algorithm only works for positive edge weight

#include <bits/stdc++.h>
using namespace std;

// Implementation of Dijkstra's Algorithm using Priority Queue
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    int E = edges.size();

    // Min Heap Priority Queue
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    // Create Adjancency list
    vector<vector<pair<int, int>>> adjList(V);

    for (auto &vec : edges)
    {
        int u = vec[0];
        int v = vec[1];
        int wt = vec[2];

        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    // Vector to store distance
    vector<int> distance(V, 1e9);

    distance[src] = 0;
    pq.push({0, src});

    // Iterate in the priority Queue
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        for (auto it : adjList[vertex])
        {
            int wt = it.second;
            int vertex = it.first;

            if (wt + dis < distance[vertex])
            {
                distance[vertex] = wt + dis;
                pq.push({distance[vertex], vertex});
            }
        }
    }

    return distance;
}
