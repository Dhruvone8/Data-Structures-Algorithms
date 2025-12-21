#include <iostream>
#include <vector>
using namespace std;

void combinations(int k, int n, int number, vector<int> &ans, vector<vector<int>> &result)
{
    if (ans.size() == k && n == 0)
    {
        result.push_back(ans);
        return;
    }

    if (ans.size() > k || n < 0 || number > 9)
    {
        return;
    }

    ans.push_back(number);
    combinations(k, n - number, number + 1, ans, result);
    ans.pop_back();
    combinations(k, n, number + 1, ans, result);
}

vector<vector<int>> combinationSumIII(int k, int n)
{
    vector<int> ans;
    vector<vector<int>> result;
    combinations(k, n, 1, ans, result);
    return result;
}

int main()
{
    vector<vector<int>> result = combinationSumIII(3, 7);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}