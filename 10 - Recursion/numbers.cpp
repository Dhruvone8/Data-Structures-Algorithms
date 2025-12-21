#include <iostream>
using namespace std;

void numbers(int i, int n)
{
    if (i > n)
    {
        return;
    }

    cout << i;
    numbers(i + 1, n);
}

int main()
{
    numbers(1, 5);
    return 0;
}