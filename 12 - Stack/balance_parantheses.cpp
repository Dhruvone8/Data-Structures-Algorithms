#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    if (s.length() == 1)    // If size of the string is 1 
    {
        return false;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')  // Push all opening brackets to the stack
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())     // If there is no opening brackets return false
            {
                return false;
            }

            if ((s[i] == '}' && st.top() == '{') ||     // If the char in the string is a closing bracket
                (s[i] == ']' && st.top() == '[') ||     // Check if the top element of the stack is its corresponding opening bracket
                (s[i] == ')' && st.top() == '('))
            {
                st.pop();   // Pop out the element
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty() == false)    // If the stack is not empty yet return false
    {
        return false;
    }

    return true;
}

int main()
{
    string s = "([])";
    cout << isValid(s);

    return 0;
}