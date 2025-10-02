// Implement Queue using Stack

/*
Steps
1. Put all elements from s1 to s2
2. Push the element x into s1
3. Put all elements from s2 to s1
*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue()
    {
    }

    void push(int x)
    {
        while(s1.size() != 0)
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(s2.size() != 0)
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int element = s1.top();
        s1.pop();
        return element;
    }

    int top()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};