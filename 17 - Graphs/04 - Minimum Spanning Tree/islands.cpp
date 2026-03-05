// GFG Link: https://www.geeksforgeeks.org/problems/number-of-islands/1

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        DisjointSet ds(n * m);
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<int> ans;
        int count = 0;

        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if (visited[row][col] == 1)
            {
                ans.push_back(count);
                continue;
            }

            visited[row][col] = 1;
            count++;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m)
                {
                    if (visited[nrow][ncol] == 1)
                    {
                        int node = row * m + col;
                        int adjNode = nrow * m + ncol;
                        if (ds.findParent(node) != ds.findParent(adjNode))
                        {
                            count--;
                            ds.unionByRank(node, adjNode);
                        }
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};
