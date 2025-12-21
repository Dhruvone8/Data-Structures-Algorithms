// Convert Array into Linked List

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

// Function to convert Array into Linked List

Node *ArrToLL(vector<int> arr)
{
    if (arr.size() == 0)
    {
        return nullptr;
    }

    Node *head = new Node(arr[0]); // Head always point to the first node
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        mover->next = new Node(arr[i]); // Create a new node and link it with the previous node
        mover = mover->next;            // Move the mover point to the next node
    }
    return head;
}

// Function to print the Linked List

void displayLL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    Node *head = ArrToLL(arr);

    cout << "Linked List: ";
    displayLL(head);
    return 0;
}
