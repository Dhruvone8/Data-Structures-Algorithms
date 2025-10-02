// Group Linked Lists with odd indices followed by Linked Lists with even Indices

#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        val = data;
        next = nullptr;
    }

    ListNode(int data, ListNode *nextptr)
    {
        val = data;
        next = nextptr;
    }
};

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *oddptr = head;
    ListNode *evenptr = head->next;
    ListNode *evenHead = evenptr;

    while (evenptr != NULL && evenptr->next != NULL)
    {
        oddptr->next = oddptr->next->next;
        oddptr = oddptr->next;
        
        evenptr->next = evenptr->next->next;;
        evenptr = evenptr->next;
    }

    oddptr->next = evenHead;

    return head;
}

ListNode *ArrToLL(vector<int> arr)
{
    if (arr.size() == 0)
    {
        return nullptr;
    }

    ListNode *head = new ListNode(arr[0]); // Head always point to the first node
    ListNode *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        mover->next = new ListNode(arr[i]); // Create a new node and link it with the previous node
        mover = mover->next;                // Move the mover point to the next node
    }
    return head;
}

// Function to print the Linked List

void displayLL(ListNode *head)
{
    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val;
        if (temp->next != nullptr)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = ArrToLL(arr);

    cout << "Original Linked List: " << endl;
    displayLL(head);

    head = oddEvenList(head);

    cout << "\nFinal Linked List: " << endl;
    displayLL(head);

    return 0;
}