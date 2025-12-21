// Delete the last node from the Linked List

#include <iostream>
#include <vector>
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
};

// Function to delete last Node

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    return head;
}

void printLinkedList(Node *head)
{
    Node *temp = head; // Temporary pointer to traverse the list

    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
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
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "Linked List before Deleting Last Element: ";
    printLinkedList(first);

    Node *head = deleteTail(first);

    cout << "Linked List after Deleting Last Element: ";
    printLinkedList(head);
}