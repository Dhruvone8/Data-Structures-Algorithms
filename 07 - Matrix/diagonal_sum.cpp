#include <iostream>
#include <vector>
using namespace std;

int primarydiagonalSum(vector<vector<int>> &mat)
{
    int sum1 = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (i == j)
            {
                sum1 += mat[i][j];
            }
        }
    }
    return sum1;
}

int secondarydiagonalsum(vector<vector<int>> &mat)
{
    int sum2 = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (i + j == mat.size() - 1)
            {
                sum2 += mat[i][j];
            }
        }
    }
    return sum2;
}

int diagonalSum(vector<vector<int>> &mat)
{
    int sum1 = primarydiagonalSum(mat);
    int sum2 = secondarydiagonalsum(mat);
    int mid;
    if(mat.size() % 2 == 1)
    {
        mid =  mat[mat.size() / 2][mat.size() / 2];
    return sum1 + sum2 - mid;
    }

    else
    {
        return sum1 + sum2;
    }
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    int sum = diagonalSum(mat);
    cout << sum;
    return 0;
}