// Leetcode Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Create Adjancency List
        vector<pair<int, int>> adjList[n];

        for (auto& it : roads) {
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }

        // Priority Queue (Stores {Time, Node})
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        // Vector to store time
        vector<long long> dist(n, LLONG_MAX);

        // Push the 0th node to the pq
        pq.push({0, 0});

        dist[0] = 0;

        vector<long long> ways(n, 0);
        ways[0] = 1;

        while (!pq.empty()) {
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (time > dist[node])
                continue;

            // Traverse adjacent nodes
            for (auto& it : adjList[node]) {
                if (it.second + time < dist[it.first]) {
                    dist[it.first] = time + it.second;
                    pq.push({dist[it.first], it.first});
                    ways[it.first] = ways[node];
                }

                else if (it.second + time == dist[it.first]) {
                    ways[it.first] = (ways[it.first] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};