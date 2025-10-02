// Print numbers from n to 1

#include <iostream>
using namespace std;

void reverse_numbers(int n, int i)
{
    if (i > n)
    {
        return;
    }

    reverse_numbers(n, i + 1);
    cout << i;
}

int main()
{
    reverse_numbers(5, 1);
    return 0;
}