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

class Queue
{
public:
    Node *front;
    Node *rear;
    int size;

    Queue()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    void enqueue(int x)
    {
        if (front == nullptr && rear == nullptr) // First element
        {
            Node *temp = new Node(x);
            front = temp;
            rear = temp;
        }
        else
        {
            Node *temp = new Node(x);
            rear->next = temp;
            rear = temp;
        }

        cout << "Pushed " << x << " into the stack" << endl;
        size++;
    }

    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty. Can't dequeue" << endl;
        }

        Node *temp = front;
        int element = temp->val;
        front = front->next;
        size--;
        cout << "Removed " << element << " from the stack" << endl;
    }

    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->val;
    }

    int length()
    {
        return size;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "The element at the front is: " << q.peek() << endl;

    cout << endl;

    q.dequeue();
    q.dequeue();

    cout << "The size of the Queue is: " << q.length() << endl;

    q.dequeue();
    q.dequeue();

    return 0;
}