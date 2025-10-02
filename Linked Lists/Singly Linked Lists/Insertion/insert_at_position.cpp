// Insert a new Node at a given position

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

Node *insert_at_position(Node *head, int pos, int val)
{
    if (head == NULL) // Linked List is Empty
    {
        if (pos == 1)
        {
            return new Node(val);
        }
    }

    if (pos == 1) // Insert a Node at the start
    {
        Node *temp = new Node(val, head);
        return temp;
    }

    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        if (count == pos - 1)
        {
            Node *newNode = new Node(val, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
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
    Node *fourth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;

    cout << "Linked List before inserting new Node: " << endl;
    printLinkedList(first);

    Node *head = insert_at_position(first, 4, 40);

    cout << "Linked List after inserting new Node: " << endl;
    printLinkedList(head);

    return 0;
}