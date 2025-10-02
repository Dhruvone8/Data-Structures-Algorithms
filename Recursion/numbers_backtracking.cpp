// Print numbers from 1 to n

#include<iostream>
using namespace std;

void numbers(int n)
{
    if (n == 0)
    {
        return;
    }

    numbers(n - 1);
    cout<<n;
}

int main()
{
    numbers(5);
    return 0;
}
