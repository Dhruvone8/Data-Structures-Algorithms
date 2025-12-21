#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

string removeKdigits(string num, int k)
{
    stack<char> st;
    string s = "";

    if (k == num.length())
    {
        return "0";
    }

    for (int i = 0; i < num.size(); i++)
    {
        while (!st.empty() && st.top() > num[i] && k > 0)
        {
            st.pop();
            k--;
        }

        st.push(num[i]);
    }

    while (k != 0)
    {
        st.pop();
        k--;
    }

    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }

    reverse(s.begin(), s.end());

    int idx = 0;

    while (idx < s.size() && s[idx] == '0')
    {
        idx++;
    }

    s = s.substr(idx);

    if(s.empty())
    {
        return "0";
    }

    return s;
}

int main()
{
    string s = "10200";

    string ans = removeKdigits(s, 1);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}