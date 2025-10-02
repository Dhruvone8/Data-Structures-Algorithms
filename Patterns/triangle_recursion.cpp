#include <iostream>
using namespace std;

void func(int row, int col)
{
    if (row == 0) // Triangle completed
    {
        return;
    }

    if (row > col)
    {
        cout << "*";
        cout<<" ";
        func(row, col + 1);
    }
    else
    {
        cout << "\n";
        func(row - 1, 0);
    }
}

int main()
{
    func(4, 0);
    return 0;
}