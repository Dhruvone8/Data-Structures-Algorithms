#include<iostream>
using namespace std;

int helper(int n , int c)
{
    if(n == 0)
    {
        return c;
    }

    int remainder = n % 10;

    if(remainder == 0)
    {
        return helper(n/10, c + 1);
    }
    else
    {
        return helper(n/10, c);
    }
}

int count_zeroes(int n)
{
    return helper(n , 0);
}


int main()
{
    cout<<count_zeroes(30501);
    return 0;
}
