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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL)
    {
        return head;
    }

    ListNode *fast = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    ListNode *slow = head;
    if(fast == NULL)
    {
        ListNode* newHead = head;
        head = head->next;
        delete newHead;
        return head;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode *delnode = slow->next;
    slow->next = slow->next->next;
    delete delnode;
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

    head = removeNthFromEnd(head, 3);
    cout << "\nFinal Linked List: " << endl;
    displayLL(head);

    return 0;
}