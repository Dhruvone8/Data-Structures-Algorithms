// Count number of prime number that are less than n

#include<iostream>
#include<vector>
using namespace std;

int count_primes(int n)
{
    vector<bool> isPrime(n, true);

    int count = 0;
    for(int i = 2; i < n; i++)
    {
        if(isPrime[i] == true)
        {
            count++;
            for(int j = i*2; j < n; j+=i)
            {
                isPrime[j] = false;      
            }
        }
    }
    return count;
}

int main()
{
    int n = 10;
    cout<<count_primes(n);
    return 0;
}