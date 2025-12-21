// Rotate Linked List to the right by k places

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

ListNode *findLastNode(ListNode *head, int n)
{
    int count = 1;
    ListNode *temp = head;

    while (temp != NULL)
    {
        if (count == n)
        {
            return temp;
        }
        count++;
        temp = temp->next;
    }

    return temp;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if(head == NULL)
    {
        return head;
    }
    
    ListNode *tail = head;
    int length = 1;

    while (tail->next != NULL)
    {
        length++;
        tail = tail->next;
    }

    if (k % length == 0)
    {
        return head;
    }

    k = k % length;
    tail->next = head;

    int n = length - k;
    ListNode *newTail = findLastNode(head, n);

    head = newTail->next;
    newTail->next = NULL;

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

    ListNode *newTail = rotateRight(head, 2);

    cout << "\nRotated Linked List: " << endl;
    displayLL(newTail);

    return 0;
}