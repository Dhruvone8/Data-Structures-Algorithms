// A digit string is good if the digits at even indices are even and the digits at odd indices are prime
// Given an integer n, return the total number of good digit strings of length n

#include <iostream>
using namespace std;

int M = 1e9 + 7;
long long power(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }

    long long half = power(a, b/2);
    long long result = (half * half) % M;

    if(b % 2 == 1)
    {
        result = (result * a) % M;
    }

    return result;
}

long long countGoodNumbers(long long n)
{
    // Find number of even digits and odd digits
    long long even_digits = (n + 1) / 2;
    long long odd_digits = n / 2;

    return (power(5, even_digits) * power(4, odd_digits)) % M;
}

int main()
{
    cout<<countGoodNumbers(4);
    return 0;
}