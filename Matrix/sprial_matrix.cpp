// Traverse the matrix in spiral order and return its elements

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> spiral_mat;

    int startrow = 0;
    int endrow = matrix.size() - 1;
    int startcol = 0;
    int endcol = matrix[0].size() - 1;

    while (startrow <= endrow && startcol <= endcol)
    {
        for (int i = startcol; i <= endcol; i++) // For Top Boundary
        {
            spiral_mat.push_back(matrix[startrow][i]);
        }

        for (int j = startrow + 1; j <= endrow; j++) // For Right Boundary
        {
            spiral_mat.push_back(matrix[j][endcol]);
        }

        for (int k = endcol - 1; k >= startcol; k--) // For Bottom Boundary
        {
            if (startrow == endrow)
            {
                break;
            }
            spiral_mat.push_back(matrix[endrow][k]);
        }

        for (int l = endrow - 1; l >= startrow + 1; l--) // For Left Boundary
        {
            if (startcol == endcol)
            {
                break;
            }
            spiral_mat.push_back(matrix[l][startcol]);
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
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = spiralOrder(mat);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}