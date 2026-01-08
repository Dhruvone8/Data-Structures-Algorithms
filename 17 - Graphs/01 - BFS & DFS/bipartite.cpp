// Leetcode Link: https://leetcode.com/problems/is-graph-bipartite/description/

#include <bits/stdc++.h>
using namespace std;

bool dfstraversal(int vertex, int color, vector<int> &visited, vector<vector<int>> &graph)
{
    visited[vertex] = color;

    for (auto it : graph[vertex])
    {
        if (visited[it] == -1)
        {
            if (dfstraversal(it, !color, visited, graph) == false)
            {
                return false;
            }
        }

        else if (visited[it] == color)
        {
            return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();

    vector<int> visited(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == -1)
        {
            if (dfstraversal(i, 0, visited, graph) == false)
                return false;
        }
    }
    return true;
}