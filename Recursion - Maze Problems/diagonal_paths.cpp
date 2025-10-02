// You can only travel Right, Downwards and Diagonally
// Goal is to reach (1,1)
// Return the total number of paths possible

#include <iostream>
using namespace std;

void print_paths_with_diagonals(string p, int rows, int cols)
{
    if (rows == 1 && cols == 1)
    {
        cout << p << " ";
        return;
    }

    if (rows > 1)
    {
        print_paths_with_diagonals(p + 'V', rows - 1, cols);
    }

    if (cols > 1)
    {
        print_paths_with_diagonals(p + 'H', rows, cols - 1);
    }

    if (cols > 1 && rows > 1)
    {
        print_paths_with_diagonals(p + 'D', rows - 1, cols - 1);
    }
}

int main()
{
    print_paths_with_diagonals("", 3, 3);
    return 0;
}