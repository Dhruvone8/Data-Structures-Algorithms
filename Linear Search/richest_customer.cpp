#include <iostream>
#include <vector>
using namespace std;

// leetcode Link: https://leetcode.com/problems/richest-customer-wealth?envType=problem-list-v2&envId=array

class Solution
{
public:
    int maxWealth = 0;
    int maximumWealth(vector<vector<int>> &accounts)
    {
        for (int customer = 0; customer < accounts.size(); customer++)
        {
            int WealthSum = 0;
            for (int wealth = 0; wealth < accounts[customer].size(); wealth++)
            {
                WealthSum += accounts[customer][wealth];
            }
            if (WealthSum > maxWealth)
            {
                maxWealth = WealthSum;
            }
        }
        return maxWealth;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> as = {{1, 2, 3}, {3, 2, 9}};
    int ans = a.maximumWealth(as);
    cout << ans;
}