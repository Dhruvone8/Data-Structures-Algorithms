#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> reshape(vector<vector<int>> &mat, int r, int c)
{
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> reshaped_matrix(r, vector<int>(c));
    if ((m * n != r * c))
    {
        return mat;
    }
    else
    {
        for (int i = 0; i < m*n; i++)
        {
            reshaped_matrix[i / c][i % c] = mat[i / n][i % n];
        }
    }
    return reshaped_matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2}, {3, 4}};
    vector<vector<int>> ans = reshape(matrix, 2, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << "";
        }
    }
    return 0;
}