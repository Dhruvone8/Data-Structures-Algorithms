#include<iostream>
#include<stack>
using namespace std;

string prefix_to_infix(string s)
{
    stack<string> st;

    for(int i = s.length() - 1; i >= 0; i--)
    {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            st.push(string(1,s[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string exp = "(" + t1 + s[i] + t2 + ")";

            st.push(exp);
        }
    }

    return st.top();
}

int main()
{
    string s = "*+PQ-MN";
    cout << "Prefix String: " << s << endl;

    string res = prefix_to_infix(s);
    cout << "Infix String: " << res << endl;

    return 0;
}