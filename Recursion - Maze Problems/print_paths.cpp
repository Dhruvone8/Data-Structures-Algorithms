// You can only travel Right and Downwards
// Goal is to reach (1,1) 
// Print the paths

#include <iostream>
using namespace std;

void path(string p, int rows, int cols)
{
    if (rows == 1 && cols == 1)
    {
        cout << p << endl;
        return;
    }

    if (rows > 1)
    {
        path(p + 'D', rows - 1, cols);
    }

    if (cols > 1)
    {
        path(p + 'R', rows, cols - 1);
    }
}

int main()
{
    path("", 3, 3);
    return 0;
}