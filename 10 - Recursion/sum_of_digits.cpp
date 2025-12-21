#include<iostream>
using namespace std;

int sum_of_digits(int n)
{
    if(n / 10 == 0)
    {
        return n;
    }

    return sum_of_digits(n / 10) + n % 10;
}

int main()
{
    cout<<sum_of_digits(1342);
    return 0;
}