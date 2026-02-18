// Leetcode Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank;
    vector<int> parent;

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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);

        int countExtras = 0;
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];

            if (ds.findParent(u) == ds.findParent(v))
            {
                countExtras++;
            }
            else
            {
                ds.unionByRank(u, v);
            }
        }

        int countComponents = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
            {
                countComponents++;
            }
        }

        int ans = countComponents - 1;

        if (countExtras >= ans)
            return ans;
        return -1;
    }
};