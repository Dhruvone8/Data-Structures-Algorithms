// Find Square Root of the number without using built-in function or x**(0.5)

#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x)
{
    if (x == 1 || x == 0)
    {
        return x;
    }

    int start = 1;
    int end = x;
    int result = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            start = mid + 1;
            return mid;   // Potential Answer
        }
        else if (mid * mid > x)
        {
            end = mid - 1;
        }
    }     
    return result;
}

int main()
{
    int x = 32;
    cout << mySqrt(x);
    return 0;
}