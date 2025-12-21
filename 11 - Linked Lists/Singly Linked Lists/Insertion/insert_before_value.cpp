// Insert a new Node before the node with given value

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

Node *insert_before_value(Node *head, int val, int element)
{
    if (head == NULL) // If linked list is empty
    {
        return NULL;
    }

    if (head->data == val) // If new node is to be inserted at the start
    {
        return new Node(element, head);
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node *newNode = new Node(element, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

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
    Node *third = new Node(40);
    Node *fourth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;

    cout << "Linked List before adding new Node: " << endl;
    printLinkedList(first);

    Node *head = insert_before_value(first, 40, 30);
    cout << "Linked List after adding new Node: " << endl;
    printLinkedList(head);

    return 0;
}