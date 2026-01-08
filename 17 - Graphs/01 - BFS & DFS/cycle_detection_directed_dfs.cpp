#include <bits/stdc++.h>
using namespace std;

bool dfs(int vertex, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &path_visited)
{
    // Mark the vertex as visited
    visited[vertex] = 1;

    // Mark the vertex visited on the path
    path_visited[vertex] = 1;

    // Traverse adjacent nodes
    for (auto it : adjList[vertex])
    {
        // If the adjacent vertex is not visited
        if (!visited[it])
        {
            // If cycle exists return true
            if (dfs(it, adjList, visited, path_visited) == true)
                return true;
        }

        // If the adjacent vertex is visited and also visited on the same path
        else if (path_visited[it])
        {
            return true;
        }
    }

    // while backtracking, unmark the vertex from the path
    path_visited[vertex] = 0;
    return false;
}

bool isCyclic(int V, vector<vector<int>> &edges)
{
    // Vector to mark the vertex visited
    vector<int> visited(V, 0);

    // Vector to mark the vertex visited in a specific path
    vector<int> path_visited(V, 0);

    // Create an Adjancency List
    vector<vector<int>> adjList(V);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            // If cycle exists return true
            if (dfs(i, adjList, visited, path_visited) == true)
            {
                return true;
            }
        }
    }

    return true;
}