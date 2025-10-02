// Delete the first element of the linked list

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

Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *temp = head; // Create a temporary pointer

    head = head->next;

    delete temp; // Deletes the node where the head pointer pointed to previously

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

    cout << "Linked List Before Deletion of Head: ";
    printLinkedList(first);

    Node* head = deleteHead(first);

    cout<< "Linked List After Deletion of Head: ";
    printLinkedList(head);
}