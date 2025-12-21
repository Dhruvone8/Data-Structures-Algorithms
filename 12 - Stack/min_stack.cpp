#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
    MinStack()
    {
    }

    stack<pair<int, int>> st;

    void push(int val)
    {
        if (st.empty()) // First Element
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};
