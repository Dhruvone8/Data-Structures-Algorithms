// Implement Queue using arrays

#include <iostream>
#include <vector>
using namespace std;

class Queue
{
public:
    int size = 5;
    int queue[5];
    int currSize = 0;
    int front = -1;
    int rear = -1;

    void enqueue(int x)
    {
        if (currSize == size)
        {
            cout << "Queue is Full" << endl;
            return;
        }

        if (currSize == 0) // Queue is empty and we are adding the first element
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        queue[rear] = x;
        currSize++;
        cout << "Pushed " << x << " into the queue" << endl;
    }

    void dequeue()
    {
        if (currSize == 0)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        int element = queue[front];
        if (currSize == 1) // If there is only 1 element in the Queue
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }

        currSize--;
        cout << "Popped " << element << " from the queue" << endl;
    }

    int peek()
    {
        if (currSize == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return queue[front];
    }

    int length()
    {
        return currSize;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << endl;

    cout << "The element at the front is: " << q.peek() << endl;
    cout << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << endl;

    cout << "The length of the Queue is: " << q.length() << endl;
    cout << "The element at the front is: " << q.peek() << endl;

    return 0;
}