// Convert infix expression to prefix expression
/*
Approach:
Reverse the given infix expression
Convert to postfix
Reverse the postfix Expression
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to check precedence of operators
int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }

    else if (c == '/' || c == '*')
    {
        return 2;
    }

    else if (c == '+' || c == '-')
    {
        return 1;
    }

    return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) // Operand
        {
            ans += s[i];
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop(); // Pop out the opening bracket
        }

        else // Operator
        {
            while (st.empty() == false &&
                   (precedence(s[i]) < precedence(st.top()) || // If the scanned char is an operator with lesser precendence than top
                    // If the scanned char is ab operator withe equal precedence as the top
                    // and top is not ^ because if follows right associativity and rest follows left associativity
                    (precedence(s[i]) == precedence(st.top()) && s[i] != '^')))
            {
                ans += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }

    // Pop all remaining elements from the stack
    while (st.empty() == false)
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string infixToPrefix(string s)
{
    // Reverse the infix expression
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }

        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    string ans = infixToPostfix(s);

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "(A+B)*C-D+F";

    cout << "Infix Expression: " << s << endl;

    string ans = infixToPrefix(s);

    cout << "Prefix Expression: " << ans << endl;

    return 0;
}