#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void combinations(vector<int> &candidates, int target, int index, int sum, vector<int> &ans, vector<vector<int>> &result)
{
    if (sum == target)
    {
        result.push_back(ans);
        return;
    }

    if (sum > target || index == candidates.size())
    {
        return;
    }

    ans.push_back(candidates[index]);
    combinations(candidates, target, index + 1, sum + candidates[index], ans, result);
    ans.pop_back();

    while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1])
    {
        index++;
    }
    combinations(candidates, target, index + 1, sum, ans, result);
}

vector<vector<int>> combinationSumII(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> ans;
    vector<vector<int>> result;
    combinations(candidates, target, 0, 0, ans, result);
    return result;
}

int main()
{
    vector<int> candidates2 = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> result = combinationSumII(candidates2, 8);

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