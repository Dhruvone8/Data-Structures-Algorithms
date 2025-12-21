#include<iostream>
using namespace std;

int count_set_bits(int n)
{
    int count = 0;
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            count++;
        }

        n = n / 2;
    }

    return count;
}

int count_set_bits_bitwise(int n)   // Alternative approach using bitwise operators
{
    int count = 0;
    while(n != 0)
    {
        n = n & n - 1;
        count++;
    }

    return count;
}

int main()
{
    int n = 23;
    cout << count_set_bits_bitwise(n);

    return 0;
}