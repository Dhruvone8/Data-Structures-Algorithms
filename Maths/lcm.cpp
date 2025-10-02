// LCM = (a * b) / GCD(a,b)

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    int g = gcd(a, b);
    return (a * b) / g;
}

int main()
{
    cout<<lcm(4, 16);
    return 0;
}