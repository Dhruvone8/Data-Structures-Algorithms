#include<iostream>
using namespace std;

int product_of_digits(int n)
{
    if (n / 10 == 0)
    {
        return n;
    }

    return product_of_digits(n / 10) * (n % 10);
}

int main()
{
    cout<<product_of_digits(45);
    return 0;
}