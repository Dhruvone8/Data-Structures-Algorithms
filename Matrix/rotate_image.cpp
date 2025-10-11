// Leetcode Link: https://leetcode.com/problems/rotate-image/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Approach:
1. Transpose the Matrix 
2. Reverse every Row
*/

void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size();

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(vector<int> &mat : matrix)
    {
        reverse(mat.begin(), mat.end());
    }
}
