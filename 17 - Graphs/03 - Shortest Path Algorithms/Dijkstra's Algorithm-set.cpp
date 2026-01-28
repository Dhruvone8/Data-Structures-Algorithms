// GFG Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    int E = edges.size();

    // Create Adjancency List
    vector<vector<pair<int, int>>> AdjList(V);

    for (auto &it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        AdjList[u].push_back({v, wt});
        AdjList[v].push_back({u, wt});
    }

    // Set
    set<pair<int, int>> st;

    // Vector to store distance
    vector<int> distance(V, 1e9);

    distance[src] = 0;
    st.insert({0, src});

    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dist = it.first;
        st.erase(it);

        // Travese adjacent vertex
        for (auto &it : AdjList[node])
        {
            int adjNode = it.first;
            int adjWt = it.second;

            if (dist + adjWt < distance[adjNode])
            {
                // Erase the existing one
                if (distance[adjNode] != 1e9)
                {
                    st.erase({distance[adjNode], adjNode});
                }

                distance[adjNode] = dist + adjWt;
                st.insert({distance[adjNode], adjNode});
            }
        }
    }
    return distance;
}
