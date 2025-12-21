#include <iostream>
#include <vector>
using namespace std;

void duplicate_combinations(vector<int> &candidates, int target, int index, int sum, vector<int> &ans, vector<vector<int>> &result)
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
    duplicate_combinations(candidates, target, index, sum + candidates[index], ans, result);

    ans.pop_back();
    duplicate_combinations(candidates, target, index + 1, sum, ans, result);
}


vector<vector<int>> combinationSumI(vector<int> &candidates, int target)
{
    vector<int> ans;
    vector<vector<int>> result;
    duplicate_combinations(candidates, target, 0, 0, ans, result);
    return result;
}

int main()
{
    vector<int> candidates1 = {2, 3, 6, 7};
    vector<vector<int>> result = combinationSumI(candidates1, 7);
    
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