// GFG Link: https://www.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex, vector<int> &visited, stack<int> &st, vector<vector<int>> &adjList)
{
    // Mark the vertex visited
    visited[vertex] = 1;

    for(auto &vec: adjList[vertex])
    {
        if(!visited[vec])
        {
            dfs(vec, visited, st, adjList);
        }
    }

    st.push(vertex);
}

vector<int> topoSort(int V, vector<vector<int>> &edges)
{
    // Array to mark the vertex visited
    vector<int> visited(V, 0);

    // Stack to store the topological sorting order
    stack<int> st;

    // Create adjancency List
    vector<vector<int>> adjList(V);

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
    }

    // Traverse the graph and call the dfs if the vertex isn't visited
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adjList);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}