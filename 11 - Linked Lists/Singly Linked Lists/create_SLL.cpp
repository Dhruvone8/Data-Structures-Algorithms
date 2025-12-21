// Create a Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;   // The value in the node
    Node *next; // next is a pointer inside a node that points to another node

    Node(int value)     // Constructor
    {
        data = value;
        next = nullptr;
    }
};

int main()
{
    // new keyword is to dynamically allocate memory

    Node *first = new Node(10);  // Creates a node with value 10
    Node *second = new Node(20); // Creates a node with value 20

    // Currently both the nodes are created separately and they are not connected with each other
    // Hence the next pointer of both the nodes is nullptr i.e they doesn't point anything

    first->next = second; // Connects first node with second node

    /*
    Visual Representation:
        first -----> second ------> nullptr
        10            20
    */

    cout << "Address of first node: " << first << endl;
    cout << "Data in first node: " << first->data << endl;

    cout << "Address of second node: " << first->next << endl;
    cout << "Data in second node: " << second->data << endl;

    cout << second->next; // End of Linked List, the next pointer of the second node points to nullptr

    return 0;
}