// GFG Link: https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findMin(int n)
{
    int count = 0;
    vector<int> denominations = {1, 2, 5, 10};
    int m = denominations.size();

    for (int i = m - 1; i >= 0; i--)
    {
        while (n >= denominations[i])
        {
            n -= denominations[i];
            count++;
        }
    }
    return count;
}

int findMinOptimal(int n)
{
    int count = 0;
    vector<int> denominations = {1, 2, 5, 10};
    int m = denominations.size();

    for(int i = m - 1; i >= 0; i--)
    {
        count += n / denominations[i];
        n %= denominations[i];
    }

    return count;
}

int main()
{
    int n = 49;

    cout << findMinOptimal(n);

    return 0;
}