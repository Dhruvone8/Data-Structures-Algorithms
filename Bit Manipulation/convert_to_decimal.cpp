#include<iostream>
#include<cmath>      
#include<algorithm>
using namespace std;

int convert2Decimal(string n)   // Convert Binary to Decimal
{
    int length = n.length();
    int result = 0;

    for(int i = 0; i < length; i++)
    {
        if(n[length - 1 - i] == '1')
        {
            result += pow(2, i);  
        }
    }

    return result;
}

int main()
{
    string n = "1101";
    cout << convert2Decimal(n);

    return 0;
}