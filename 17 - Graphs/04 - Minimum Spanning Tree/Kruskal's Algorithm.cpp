#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank;
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int up = findParent(u);
        int vp = findParent(v);
        if (up == vp)
            return;
        if (rank[up] < rank[vp])
        {
            parent[up] = vp;
        }
        else if (rank[vp] < rank[up])
        {
            parent[vp] = up;
        }
        else
        {
            parent[vp] = up;
            rank[up]++;
        }
    }
};

class Solution
{
public:
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        vector<pair<int, pair<int, int>>> edgesList;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            edgesList.push_back({wt, {u, v}});
        }

        DisjointSet ds(V);

        // Sort by edges
        sort(edgesList.begin(), edgesList.end());

        int mstWt = 0;

        for (auto it : edgesList)
        {
            int wt = it.first;
            int node = it.second.first;
            int adjNode = it.second.second;

            if (ds.findParent(node) != ds.findParent(adjNode))
            {
                mstWt += wt;
                ds.unionByRank(node, adjNode);
            }
        }

        return mstWt;
    }
};