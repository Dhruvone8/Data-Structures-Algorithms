// You can only travel Right and Downwards
// Goal is to reach (1,1)
// Return the total number of paths possible

#include <iostream>
using namespace std;

int path_count(int rows, int cols)
{
    if (rows == 1 || cols == 1)
    {
        return 1;
    }

    int left = path_count(rows - 1, cols);
    int right = path_count(rows, cols - 1);

    return left + right;
}

int main()
{
    cout << path_count(3, 3);
    return 0;
}