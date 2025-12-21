#include <iostream>
using namespace std;

pair<int, int> LinearSearchIn2DArray(int arr[][3], int rows, int columns, int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] == target)
            {
                cout << "The Target Element is at the position: {" << i << "," << j << "}" << endl;
                return {i, j}; // Returns both row and column
            }
        }
    }
    return {-1, -1}; // Returns -1, -1 if not found
}

int LinearSearchMax(int arr[][3], int rows, int columns)
{
    int max = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int main()
{
    int nums[4][3] =
        {
            {8, 2, 3},
            {9, 6, 89},
            {6, 10, 11},
            {5, 13, 14}};
    pair<int, int> result = LinearSearchIn2DArray(nums, 4, 3, 12);
    if (result.first == -1)
    {
        cout << "Element not found! " << endl;
    }

    int Maximum = LinearSearchMax(nums, 4, 3);
    cout << "Largest Element in the array is: " << Maximum;

    return 0;
}
