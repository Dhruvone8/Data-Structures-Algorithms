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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;

    ListNode *dummy = new ListNode(-1);
    int carry = 0;
    ListNode *curr = dummy;

    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1 != NULL)
        {
            sum = sum + temp1->val;
        }

        if (temp2 != NULL)
        {
            sum = sum + temp2->val;
        }

        ListNode *newNode = new ListNode(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if (temp1 != NULL)
        {
            temp1 = temp1->next;
        }

        if (temp2 != NULL)
        {
            temp2 = temp2->next;
        }
    }

    if (carry != 0)
    {
        ListNode *newNode = new ListNode(carry);
        curr->next = newNode;
    }

    return dummy->next;
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
    vector<int> v1 = {2, 4, 3};
    vector<int> v2 = {5, 6, 4};

    ListNode *h1 = ArrToLL(v1);
    ListNode *h2 = ArrToLL(v2);

    ListNode *head = addTwoNumbers(h1, h2);

    cout << "Final Linked List: " << endl;
    displayLL(head);
}