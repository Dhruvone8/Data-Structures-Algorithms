#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool isPrime(int n)
{
    for(int i = 2; i < sqrt(n); i++)    // Check till square root of n because after there, numbers are repeated
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout<<isPrime(41);
    return 0;
}