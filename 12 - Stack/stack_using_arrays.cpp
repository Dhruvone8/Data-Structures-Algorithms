// Implement Stack using Arrays

#include <iostream>
using namespace std;

class Stack
{
public:
    int top = -1;
    int stack[5];

    void push(int x) // Adding an element to the Stack
    {
        if (top >= 4)
        {
            cout << "Stack is Full" << endl;
            return;
        }

        top = top + 1;
        stack[top] = x;
        cout << "Pushed " << x << " in the stack" << endl;
    }

    int peek() // Return the element at the top
    {
        if (top == -1)
        {
            cout << "Stack is empty";
            return -1;
        }

        return stack[top];
    }

    void pop() // Remove the last element from the stack
    {
        if (top == -1)
        {
            cout << "Stack is empty";
            return;
        }

        int element = stack[top];

        top--;
        cout << "Popped " << element << " from the stack" << endl;
    }

    int size() // Return the size if the stack
    {
        return top + 1;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout << endl;

    cout << "The element at the top is: " << s.peek() << endl;
    cout << "The size of the stack is: " << s.size() << endl;
    cout << endl;

    s.pop();
    cout << endl;

    cout << "Top element after pop: " << s.peek() << endl;
    cout << "Size of the Stack after pop: " << s.size() << endl;

    return 0;
}