#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) 
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposeMatrix(cols, vector<int>(rows));

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            transposeMatrix[i][j] = matrix[j][i];
        }
    }
    return transposeMatrix;
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans = transpose(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[0].size(); j++)
        {
        cout << ans[i][j] << " ";
        }
    }
    return 0;
}