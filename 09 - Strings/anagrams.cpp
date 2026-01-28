// Leetcode Link: https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    if (strs.size() == 0)
    {
        return {{""}};
    }

    if (strs.size() == 1)
    {
        return {{strs[0]}};
    }

    unordered_map<string, vector<string>> hash;

    for (auto str : strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        hash[key].push_back(str);
    }

    vector<vector<string>> result;
    for (auto &it : hash)
    {
        result.push_back({it.second});
    }

    return result;
}