#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj)
{
    // No. of vertices
    int v = adj.size();

    // Create a visited array to keep the track of visited nodes
    vector<int> visited(v, 0);

    // Always Mark first node as visited
    visited[0] = 1;

    // Create a Queue and push the starting node
    queue<int> q;
    q.push(0);

    vector<int> ans;

    while (!q.empty())
    {
        int currnode = q.front();
        q.pop();
        ans.push_back(currnode);

        for(auto it : adj[currnode])
        {
            if(visited[it] == 0)
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    return ans;
}