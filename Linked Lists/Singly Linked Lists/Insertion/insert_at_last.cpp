// Insert a new node at the last position

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

Node *insert_at_last(Node *head, int val)
{

    if (head == NULL)
    {
        return new Node(val);
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(val);
    temp->next = newNode;

    return head;
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

    cout << "Linked List before inserting a new Node at the end: " << endl;
    printLinkedList(first);

    Node *head = insert_at_last(first, 50);

    cout << "Linked List after inserting a new Node at the end: " << endl;

    printLinkedList(head);

    return 0;
}
