// Implement Stack using Queue

#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    MyStack()
    {

    }

    queue<int> q;

    void push(int x)
    {
        int s = q.size();
        q.push(x);

        for(int i = 1; i <= s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int element = q.front();
        q.pop();
        return element;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};