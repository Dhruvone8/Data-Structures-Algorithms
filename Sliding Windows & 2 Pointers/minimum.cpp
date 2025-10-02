// Leetcode Link: https://leetcode.com/problems/minimum-window-substring/description/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string minWindow(string s, string t)
{
    int n = s.length();
    int m = t.length();
    int left = 0;
    int right = 0;
    int minlen = INT32_MAX;
    int sIndex = -1;
    int count = 0;
    vector<int> hash(256, 0);

    if (t.empty() || s.empty())
    {
        return "";
    }

    for (int i = 0; i < t.length(); i++)
    {
        hash[t[i]]++;
    }

    while (right < n)
    {
        if (hash[s[right]] > 0) // The char in the s string is present in the t string already
        {
            count++;
        }

        hash[s[right]]--; // Decrease the frequency of that char in the hashmap

        while (count == m) // Valid Answer
        {
            if ((right - left + 1) < minlen)
            {
                minlen = (right - left + 1);
                sIndex = left;
            }

            hash[s[left]]++;

            if (hash[s[left]] > 0)
            {
                count--;
            }
            left++;
        }

        right++;
    }

    if (sIndex == -1)
    {
        return "";
    }

    return s.substr(sIndex, minlen);
}

int main()
{
    string s = "ddaaabbca";
    string t = "abc";

    string ans = minWindow(s, t);

    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}