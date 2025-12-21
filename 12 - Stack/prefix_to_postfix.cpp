#include<iostream>
#include<stack>
using namespace std;

string prefix_to_postfix(string s)
{
    stack<string> st;

    for(int i = s.length() - 1; i >= 0; i--)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string exp = t1 + t2 + s[i];

            st.push(exp);
        }
    }

    return st.top();
}

int main()
{
    string s = "/-AB*+DEF";
    cout << "Prefix String: " << s << endl;

    string res = prefix_to_postfix(s);
    cout << "Postfix String: " << res << endl;
    
    return 0;
}