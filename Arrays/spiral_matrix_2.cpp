// Adds values inside the matrix in spiral order

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> spiral_mat(n, vector<int>(n));

    int startrow = 0;
    int endrow = n - 1;
    int startcol = 0;
    int endcol = n - 1;

    int value = 1;

    while (startrow <= endrow && startcol <= endcol)
    {
        for (int i = startcol; i <= endcol; i++) // For Top Boundary
        {
            spiral_mat[startrow][i] = value;
            value += 1;
        }

        for (int j = startrow + 1; j <= endrow; j++) // For Right Boundary
        {
            spiral_mat[j][endcol] = value;
            value += 1;
        }

        for (int k = endcol - 1; k >= startcol; k--) // For Bottom Boundary
        {
            spiral_mat[endrow][k] = value;
            value += 1;
        }

        for (int l = endrow - 1; l >= startrow + 1; l--) // For Left Boundary
        {
            spiral_mat[l][startcol] = value;
            value += 1;
        }

        startrow++;
        endrow--;
        startcol++;
        endcol--;
    }

    return spiral_mat;
}

int main()
{
    int n = 3;
    vector<vector<int>> ans = generateMatrix(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }
    return 0;
}