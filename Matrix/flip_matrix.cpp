#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> flipmat(vector<vector<int>> &matrix)
{
    int rowsize = matrix.size();
    int colsize = matrix[0].size();
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize/2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][colsize - (j+1)];
            matrix[i][colsize - (j+1)] = temp;
        }
    }
    return matrix;
}

int main()
{
    vector<vector<int>> mat = {{1,1,0},{1,0,1},{0,0,0}};
    vector<vector<int>> ans = flipmat(mat);
    for (int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[0].size(); j++)
        {
        cout << ans[i][j] << " ";
        }
    }
    return 0;
}