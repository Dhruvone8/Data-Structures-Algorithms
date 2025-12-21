#include <iostream>
#include <vector>
using namespace std;

vector<int> binary_search_matrix_asc(vector<vector<int>> &matrix, int target)
{
    int row = 0;
    int col = matrix[0].size() - 1;

    while (row < matrix.size() && col >= 0)
    {
        if (matrix[row][col] == target)
        {
            return {row, col};
        }
        else if (matrix[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> matrix = {{8, 10, 38}, {45, 48, 57}, {62, 63, 81}};
    vector<int> ans = binary_search_matrix_asc(matrix, 38);
    if (ans[0] != -1)
    {
        cout << "Target element is found at index: " << "{" << ans[0] << "," << ans[1] << "}" << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }

    return 0;
}