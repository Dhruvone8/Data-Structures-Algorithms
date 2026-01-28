// Leetcode Link: https://leetcode.com/problems/backspace-string-compare/description/

#include <iostream>
using namespace std;

bool backspaceCompare(string s, string t)
{
    int n = s.length();
    int m = t.length();

    string s1 = "";
    string t1 = "";

    int hashCount = 0;

    // Traverse first string from the end
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '#')
        {
            hashCount++;
        }

        else if (s[i] != '#' && hashCount > 0)
        {
            hashCount--;
            continue;
        }

        else
        {
            s1 += s[i];
        }
    }

    hashCount = 0;

    // Traverse second string from end
    for (int i = m - 1; i >= 0; i--)
    {
        if (t[i] == '#')
        {
            hashCount++;
        }

        else if (t[i] != '#' && hashCount > 0)
        {
            hashCount--;
            continue;
        }

        else
        {
            t1 += t[i];
        }
    }

    cout << s1 << endl;
    cout << t1;

    return s1 == t1;
}

int main()
{
    string s = "xywrrmp";
    string t = "xywrrmu#p";

    bool ans = backspaceCompare(s, t);

    cout << ans;

    return 0;
}