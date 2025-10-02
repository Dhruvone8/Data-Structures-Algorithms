// Given Matrix is in non - increasing order (both row and column wise)

#include <iostream>
#include <vector>
using namespace std;

int countNegatives(vector<vector<int>> &grid)
{
    int row = grid.size() - 1;
    int col = 0;
    int total_cols = grid[0].size();
    int count = 0;

    while (row >= 0 && col < total_cols)
    {
        if (grid[row][col] < 0)
        {
            count = count + (total_cols - col);
            row--;
        }
        else
        {
            col++;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> nums = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    int ans = countNegatives(nums);
    cout << ans;
    return 0;
}