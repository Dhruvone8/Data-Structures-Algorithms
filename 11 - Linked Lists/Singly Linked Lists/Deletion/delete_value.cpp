// You are given a value, delete the first node with that value

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
};

Node *delete_value(Node *head, int element)
{
    if (head->data == element) // Delete the head if head node has the required data
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == element)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }

        prev = temp;
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
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "Linked List before Deleting node with given value: ";
    printLinkedList(first);

    Node* head = delete_value(first, 40);

    cout << "Linked List after Deleting node with given value: ";
    printLinkedList(head);

    return 0;
}