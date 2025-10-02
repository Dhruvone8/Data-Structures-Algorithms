// Convert string into integer

#include <iostream>
using namespace std;

int myAtoi(string s)
{
    int i = 0;
    int result = 0;
    int sign = 1;
    int n = s.length();

    while (i < n && s[i] == ' ') // Skip trailing white spaces
    {
        i++;
    }

    if (i < n && (s[i] == '-' || s[i] == '+')) // Checks only one sign (If two signs are present)
    {
        if (s[i] == '-')
        {
            sign = -1;
        }
        else
        {
            sign = 1;
        }

        i++;
    }

    while ((i < s.length()) && (s[i] >= '0' && s[i] <= '9'))    // Only processes digits
    {
        result = result * 10 + (s[i] - '0');
        if (result * sign > INT32_MAX)
        {
            return INT32_MAX;
        }

        if (result * sign < INT32_MIN)
        {
            return INT32_MIN;
        }
        i++;
    }
    return result;
}

int main()
{
    int ans = myAtoi("123");
    cout<<ans;
    return 0;
}