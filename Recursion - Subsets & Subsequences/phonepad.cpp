// Google Interview Question

#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char, string> keypad = 
{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

vector<string> pad(string p, string up, vector<string> &results)
{
    if (up.empty())
    {
        results.push_back(p);
        return results;
    }

    char digit = up[0];

    string letters = keypad[digit];

    for (char ch : letters)
    {
        pad(p + ch, up.substr(1), results);
    }

    return results;
}

int main()
{
    vector<string> results;
    vector<string> ans = pad("", "23", results);

    for (string val : ans)
    {
        cout << val << " ";
    }

    return 0;
}
