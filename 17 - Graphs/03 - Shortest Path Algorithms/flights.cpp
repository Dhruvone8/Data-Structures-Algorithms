// Leetcode Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    // Create adjancency list
    vector<pair<int, int>> adjList[n];
    for (auto it : flights)
    {
        adjList[it[0]].push_back({it[1], it[2]});
    }

    // Queue (Stores {stops, nodes, distance})
    queue<pair<int, pair<int, int>>> q;
    q.push({{0}, {src, 0}});

    // Vector to track cost
    vector<int> cost(n, 1e9);
    cost[src] = 0;

    while (!q.empty())
    {
        int stops = q.front().first;
        int city = q.front().second.first;
        int fare = q.front().second.second;
        q.pop();

        // If stops exceeds thr given limit, continue
        if (stops > k)
            continue;

        // Traverse adjacent cities
        for (auto it : adjList[city])
        {
            int adjCity = it.first;
            int adjFare = it.second;

            if (adjFare + fare < cost[adjCity] && stops <= k)
            {
                cost[adjCity] = adjFare + fare;
                q.push({{stops + 1}, {adjCity, adjFare + fare}});
            }
        }
    }

    if (cost[dst] == 1e9)
        return -1;
    return cost[dst];
}