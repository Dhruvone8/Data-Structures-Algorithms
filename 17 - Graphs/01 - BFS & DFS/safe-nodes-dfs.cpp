// Leetcode Link: https://leetcode.com/problems/find-eventual-safe-states/description/

#include <bits/stdc++.h>
using namespace std;

bool dfs(int vertex, vector<int> &visited, vector<int> &pathVisited, vector<int> &check, vector<vector<int>> &graph)
{
    // Mark the node as visited
    visited[vertex] = 1;

    // Mark the node as path visited
    pathVisited[vertex] = 1;

    // Traverse the adjancency list
    for(auto &vec : graph[vertex])
    {
        // If its not visited
        if(!visited[vec])
        {
            // If cycle exists
            if(dfs(vec, visited, pathVisited, check, graph) == true) return true;
        }

        // Visited as well as path visited
        else if(pathVisited[vec] == 1)
        {
            return true;
        }
    }

    check[vertex] = 1;
    pathVisited[vertex] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();

    // Visited Array
    vector<int> visited(n, 0);

    // Path visited Array
    vector<int> pathVisited(n, 0);

    // array to check if node is safe or not
    vector<int> check(n ,0);

    // array to store ans
    vector<int> ans;

    // Call for dfs
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, visited, pathVisited, check, graph);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(check[i] == 1)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    vector<int> ans = eventualSafeNodes(graph);

    for(auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}