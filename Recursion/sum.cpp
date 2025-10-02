// Sum of digits from 1 to n
#include <iostream>
using namespace std;

int functional_sum(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }   

    return n + functional_sum(n - 1);
}

void parameterised_sum(int n, int sum)
{
    if(n == 0)
    {
        cout<<sum;
        return;
    }
    
    parameterised_sum(n - 1, sum + n);

}

int main()
{
    cout << functional_sum(10)<<endl;
    parameterised_sum(15, 0);
    return 0;
}