// Leetcode Link: https://leetcode.com/problems/find-center-of-star-graph/

#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>& edges) 
{
   int n = edges.size() + 1;
   
   vector<int> count(n, 0);

   for(auto it : edges)
   {
        int u = it[0];
        int v = it[1];

        count[u]++;
        count[v]++;
   }

   for(int i = 1; i <= count.size(); i++)
   {
        if(count[i] == n - 1)
        {
            return i;
        }
   }

   return -1;
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};
    int ans = findCenter(edges);

    cout << ans;

    return 0;
}