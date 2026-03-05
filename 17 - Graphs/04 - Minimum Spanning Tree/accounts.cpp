// Leetcode Link: https://leetcode.com/problems/accounts-merge/

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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }
                else
                {
                    ds.unionByRank(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergeMail[n];

        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergeMail[i].size() == 0)
                continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergeMail[i])
            {
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};