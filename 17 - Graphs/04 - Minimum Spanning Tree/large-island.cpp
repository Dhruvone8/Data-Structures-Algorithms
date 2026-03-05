// Leetcode Link: https://leetcode.com/problems/making-a-large-island/description/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
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

    void unionBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Connect Components

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int idx = 0; idx < 4; idx++)
                {
                    int nrow = row + dr[idx];
                    int ncol = col + dc[idx];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n)
                    {
                        if (grid[nrow][ncol] == 1)
                        {
                            int nodeNo = row * n + col;
                            int adjNodeNo = row * n + ncol;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }

        int maxsize = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int idx = 0; idx < 4; idx++)
                {
                    int nrow = row + dr[idx];
                    int ncol = col + dc[idx];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n)
                    {
                        if (grid[nrow][ncol] == 1)
                        {
                            components.insert(ds.findParent(nrow * n + ncol));
                        }
                    }
                }

                int size = 1;
                for (auto it : components)
                {
                    size += ds.size[it];
                }
                maxsize = max(size, maxsize);
            }
        }

        // If all are 1s
        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {
            maxsize = max(maxsize, ds.size[ds.findParent(cellNo)]);
        }

        return maxsize;
    }
};