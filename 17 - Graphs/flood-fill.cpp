// Leetcode Link: https://leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

void BFSTraversal(int n, int m, int sr, int sc, int color, vector<vector<int>> &colored, vector<vector<int>> &image)
{
    // Color the starting cell
    colored[sr][sc] = color;

    queue<pair<int, int>> q;
    q.push({sr, sc});

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // Traverse the 4 neighbors
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && colored[nrow][ncol] == image[sr][sc] && colored[nrow][ncol] != color)
            {
                colored[nrow][ncol] = color;
                q.push({nrow, ncol});
            }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();

    // Matrix to color the image
    vector<vector<int>> colored = image;

    BFSTraversal(n, m, sr, sc, color, colored, image);

    return colored;
}