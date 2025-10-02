// Leetcode Link: https://leetcode.com/problems/lemonade-change/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool lemonadeChange(vector<int>& bills) 
{
    int n = bills.size();
    
    int five_dollar = 0;
    int ten_dollar = 0;

    for(int i = 0; i < n; i++)
    {
        if(bills[i] == 5)
        {
            five_dollar++;
        }

        else if(bills[i] == 10)
        {
            if(five_dollar == 0)
            {
                return false;
            }

            ten_dollar++;
            five_dollar--;
        }

        else
        {
            if(ten_dollar >= 1 && five_dollar >= 1)
            {
                five_dollar--;
                ten_dollar--;
            }

            else if(five_dollar >= 3)
            {
                five_dollar -= 3;
            }

            else
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<int> bills = {5, 5, 10, 10, 20};
    cout << lemonadeChange(bills);
    return 0;
}