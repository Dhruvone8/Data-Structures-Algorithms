#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = nullptr;
    }
};

class Stack
{
public:
    Node *top;
    int size;

    Stack()
    {
        top = nullptr;
        size = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
        cout << "Pushed " << x << " into the stack" << endl;
    }

    int pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty, cannot pop!" << endl;
            return -1; // Error value
        }
        Node *temp = top;
        int element = temp->val;
        top = top->next;
        delete temp;
        size--;
        cout << "Removed " << element << " from the stack" << endl;
        return element;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty!" << endl;
            return -1; // Error value
        }
        return top->val;
    }

    int length()
    {
        return size;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << endl;

    cout << "Top element is: " << s.peek() << endl;
    cout << "Stack size is: " << s.length() << endl;

    cout << endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
