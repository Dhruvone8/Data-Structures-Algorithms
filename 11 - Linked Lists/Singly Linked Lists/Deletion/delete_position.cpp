// Delete the Kth node of the Linked List

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

Node *delete_position(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    if (k == 1) // delete the head
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        count++;
        if (count == k)
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

    cout << "Linked List before Deleting kth position node: ";
    printLinkedList(first);

    Node* head = delete_position(first, 3);

    cout << "Linked List after Deleting kth position node: ";
    printLinkedList(head);

    return 0;
}