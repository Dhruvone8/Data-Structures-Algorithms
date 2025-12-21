// Print numbers from n to 1

#include<iostream>
using namespace std;

void reverse_numbers(int n)
{
    if(n == 0)
    {
        return;
    }

    cout<<n;
    reverse_numbers(n - 1);
}

int main()
{
    reverse_numbers(5);
    return 0;
}