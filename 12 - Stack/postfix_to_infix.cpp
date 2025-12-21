#include <iostream>
#include <stack>
using namespace std;

string postfixToInfix(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            st.push(string(1, s[i]));
        }

        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string exp = "(" + t2 + s[i] + t1 + ")";
            st.push(exp);
        }
    }

    return st.top();
}

int main()
{
    string s = "AB-DE+F*/";
    cout << "Postfix String: " << s << endl;

    string res = postfixToInfix(s);
    cout << "Infix String: " << res << endl;

    return 0;
}