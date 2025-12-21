#include<iostream>
using namespace std;

bool isOdd(int n)
{
    if(n & 1 == 1) 
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cout<<isOdd(18);
    return 0;
}