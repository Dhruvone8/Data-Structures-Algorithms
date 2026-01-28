// GFG Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

// Approach
// Step - 1 : Perform Topo Sort on the Graph
// Step - 2 : Take Nodes from the stack one by one & Relax the edges

void toposort(int vertex, vector<vector<pair<int, int>>> &adjList, vector<int> &visited, stack<int> &st)
{
    visited[vertex] = 1;

    // Traverse the adjancency List
    for (auto &it : adjList[vertex])
    {
        int v = it.first;
        if (!visited[v])
        {
            toposort(vertex, adjList, visited, st);
        }
    }

    st.push(vertex);
}

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    // Create Adjancency List that stores the neighbor node along with its weight
    vector<vector<pair<int, int>>> adjList(V);

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adjList[u].push_back({v, wt});
    }

    // Find Topo Sort
    vector<int> visited(V, 0);

    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            toposort(i, adjList, visited, st);
        }
    }

    // Find distance
    vector<int> distance(V, -1);

    // Distance from source to source is always 0
    distance[0] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto &it : adjList[node])
        {
            int v = it.first;
            int wt = it.second;

            if (distance[node] + wt < distance[v])
            {
                distance[v] = distance[node] + wt;
            }
        }
    }

    return distance;
}