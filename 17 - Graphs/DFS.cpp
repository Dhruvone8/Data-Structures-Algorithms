#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans)
{
    // Mark the node as visited
    visited[node] = 1;
    ans.push_back(node);

    // Traverse all the nighbors recursively
    for(auto it : adj[node])
    {
        // If the node is not visited
        if(visited[it] == 0)
        {
            dfsHelper(it, adj, visited, ans);
        }
    }
}

vector<int> dfs(vector<vector<int>>& adj) 
{
    // Number of vertices
    int v = adj.size();

    // Create a visited array to mark the nodes that are visited
    vector<int> visited(v, 0);

    // Starting node is 0
    int start = 0;

    vector<int> ans;

    dfsHelper(start, adj, visited, ans);

    return ans;
}