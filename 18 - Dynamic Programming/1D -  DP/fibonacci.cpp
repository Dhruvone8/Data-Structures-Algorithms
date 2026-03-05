#include <bits/stdc++.h>
using namespace std;

// Using Memoization

// Time Complexity : O(n)
// Space Complexity  O(n) + O(n)
int fibo_memoization(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibo_memoization(n - 1, dp) + fibo_memoization(n - 2, dp);
}

// Using Tabulation
// Time Complexity = O(n);
// Space Complexity = O(n);
int fibo_tabulation(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Space Optimization
// Time Complexity = O(n);
// Space Complexity = O(1);
int fibo_tabulation_optimised(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    int curr;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << fibo_memoization(n, dp);
    // cout << fibo_tabulation(n, dp);
    cout << fibo_tabulation_optimised(n);
    return 0;
}