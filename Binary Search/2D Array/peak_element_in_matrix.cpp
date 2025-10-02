#include <iostream>
#include <vector>
using namespace std;

int find_max_row_index(vector<vector<int>> &matrix, int m, int n, int col) // Find maximum element in the mid column and return its row index
{
    int max_element = INT32_MIN;
    int row_index = -1;

    for (int i = 0; i < m; i++)
    {
        if (matrix[i][col] > max_element)
        {
            max_element = matrix[i][col];
            row_index = i;
        }
    }
    return row_index;
}

vector<int> findPeakGrid(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int start = 0;
    int end = cols - 1;

    int left = -1;
    int right = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        int max_row_index = find_max_row_index(matrix, rows, cols, mid);

        if (mid - 1 >= 0)
        {
            left = matrix[max_row_index][mid - 1];
        }
        else
        {
            left = -1;
        }

        if (mid + 1 < cols)
        {
            right = matrix[max_row_index][mid + 1];
        }
        else
        {
            right = -1;
        }

        if ((matrix[max_row_index][mid] > left) && (matrix[max_row_index][mid] > right))
        {
            return {max_row_index, mid};
        }

        else if (matrix[max_row_index][mid] < left)
        {
            end = mid - 1;
        }

        else if (matrix[max_row_index][mid] < right)
        {
            start = mid + 1;
        }
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> matrix = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
    vector<int> ans = findPeakGrid(matrix);
    cout << "{" << ans[0] << "," << ans[1] << "}";
    return 0;
}