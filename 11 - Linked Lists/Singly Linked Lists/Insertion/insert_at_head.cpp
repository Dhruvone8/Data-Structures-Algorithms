// Insert a node at the start of the linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }

    Node(int value, Node *nextptr)
    {
        data = value;
        next = nextptr;
    }
};

Node *insert_at_head(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;
}

void printLinkedList(Node *head)
{
    Node *temp = head; // Temporary pointer to traverse the list

    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " -> ";
        }

        temp = temp->next; // Move to next node
    }

    cout << " -> NULL" << endl;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;

    cout << "Linked List before inserting new Node at the head: " << endl;
    printLinkedList(first);

    Node *head = insert_at_head(first, 5);

    cout << "Linked List after inserting new Node at the head: " << endl;
    printLinkedList(head);

    return 0;
}