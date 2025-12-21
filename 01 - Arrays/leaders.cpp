// GFG Link: https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leaders(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    int leader = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= leader)
        {
            ans.push_back(arr[i]);
        }

        leader = max(leader, arr[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {17, 15, 10, 40, 1};

    vector<int> ans = leaders(arr);

    for(int a : ans)
    {
        cout << a << " ";
    }

    return 0;
}