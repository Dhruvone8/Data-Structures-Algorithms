// Divide 2 integers without using multiplication, divison and mod operator

#include<iostream>
#include<cmath>
using namespace std;

int divide(int dividend, int divisor)
{
    int ans = 0;    
    bool sign = true;  // Positive

    if(dividend == divisor)
    {
        return 1;
    }

    if(dividend == 0)
    {
        return 0;
    }

    if(dividend < 0 && divisor > 0)
    {
        sign = false;   // Negative
    }

    if(dividend > 0 && divisor < 0)
    {
        sign = false;
    }

    // Solve by taking positive values of dividend and 
    int n = abs(dividend);  
    int d = abs(divisor);

    while(n >= d)
    {
        int count = 0;

        while(n >= (d << (count + 1)))
        {
            count++;
        }

        ans += (1 << count);
        n = n - (d << count);
    }
    
    if(ans >= INT32_MAX && sign == true)
    {
        return INT32_MAX;
    }

    if(ans >= INT32_MAX && sign == false)
    {
        return INT32_MIN;
    }
    
    if(sign == false)
    {
        return -1 * ans;
    }

    return ans;   
}

int main()
{
    int dividend = 21;
    int divisor = 7;

    cout << divide(dividend, divisor);

    return 0;
}