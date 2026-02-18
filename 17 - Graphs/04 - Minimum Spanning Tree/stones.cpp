// Leetcode Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();

        int maxRow = 0;
        int maxCol = 0;

        for (auto &it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol);
        unordered_set<int> nodes;
        for (auto &it : stones)
        {
            int rowNode = it[0];
            int colNode = it[1] + maxRow + 1;
            ds.unionByRank(rowNode, colNode);
        }

        int components = 0;
        for (int it : nodes)
        {
            if (ds.findParent(it) == it)
                components++;
        }
        return stones.size() - components;
    }
};
