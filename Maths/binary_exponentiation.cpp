// Efficient to calculate large powers
// Also known as fast exponentiation

#include <iostream>
using namespace std;

int power(long a, long b)
{
    if (b == 0)
    {
        return 1;
    }

    if (b % 2 == 0) // If power is even
    {
        return power(a * a, b / 2);
    }
    else
    {
        return a * power(a, b - 1);
    }
}

int main()
{
    cout << power(2, 10);
    return 0;
}