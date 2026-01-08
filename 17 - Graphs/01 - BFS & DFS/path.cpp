// Leetcode Link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/

#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(int node, vector<vector<int>> &adjList, vector<int> &visited, int destination)
{
    visited[node] = 1;
    if(visited[destination] == 1) return;

    for(auto &vec : adjList[node])
    {
        if(!visited[vec])
        {
            dfsTraversal(vec, adjList, visited, destination);
        }
    }
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    // Create Adjancency List
    vector<vector<int>> adjList(n);

    for (auto &vec : edges)
    {
        adjList[vec[0]].push_back(vec[1]);
        adjList[vec[1]].push_back(vec[0]);
    }

    // Create a visited array to mark the nodes that are visited
    vector<int> visited(n, 0);

    dfsTraversal(source, adjList, visited, destination);

    if(visited[destination] == 0) return false;

    return true;
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};

    cout << validPath(3, edges, 0, 2);
    return 0;
}