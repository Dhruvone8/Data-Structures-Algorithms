// Make Partitions in a given string s such that each partition is a palindrome

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    int n = s.size() - 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != s[n - i])
        {
            return false;
        }
    }
    return true;
}

void solve(string processed, string unprocessed, vector<string> &ans, vector<vector<string>> &result)
{
    if (unprocessed.empty())
    {
        result.push_back(ans);
        return;
    }

    for (int i = 1; i <= unprocessed.length(); i++)
    {
        // Making a partition 
        string processed = unprocessed.substr(0, i);

        // Checking if the string before the partition is Palindrome or not
        if (isPalindrome(processed))
        {
            ans.push_back(processed);

            // Make other partitions 
            solve(processed, unprocessed.substr(i), ans, result);

            // Backtrack
            ans.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<string> ans;
    vector<vector<string>> result;
    solve("", s, ans, result);
    return result;
}

int main()
{
    vector<vector<string>> result = partition("aab");
    for (vector<string> vecstrings : result)
    {
        for (string strings : vecstrings)
        {
            cout << strings << " ";
        }
        cout << endl;
    }
    return 0;
}
