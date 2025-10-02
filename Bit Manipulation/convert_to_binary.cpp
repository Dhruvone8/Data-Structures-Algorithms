#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string convert2Binary(int n) // Convert Decimal To Binary
{
    if(n == 0)
    {
        return "0";
    }

    string result = "";
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            result += "0";
        }
        else
        {
            result += "1";
        }

        n = n / 2;
    }
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    int n = 13;
    string r = convert2Binary(n);
    for (auto c : r)
    {
        cout << c;
    }

    return 0;
}
