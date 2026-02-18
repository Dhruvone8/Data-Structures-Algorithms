// Leetcode Link: https://leetcode.com/problems/network-delay-time/description/

#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    // Create Adjancency List
    vector<pair<int, int>> adjList[n + 1];

    for (auto &it : times)
    {
        int u = it[0];
        int v = it[1];
        int t = it[2];

        adjList[u].push_back({v, t});
    }

    // Priority Queue (Stores {time, node})
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    pq.push({0, k});

    // Distance vector
    vector<int> dist(n + 1, 1e9);
    dist[k] = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int time = pq.top().first;
        pq.pop();

        // Traverse the adjancency List
        for (auto it : adjList[node])
        {
            // If shorter path to the neighbor is found
            if (time + it.second < dist[it.first])
            {
                dist[it.first] = time + it.second;

                pq.push({dist[it.first], it.first});
            }
        }
    }

    int ans = *max_element(dist.begin() + 1, dist.end());
    return ans == 1e9 ? -1 : ans;
}