// Remove all Nodes with the value given

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
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *curr = dummy;

    while (curr->next != NULL)
    {
        if (curr->next->val == val)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
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
        mover = mover->next;            // Move the mover point to the next node
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
    vector<int> arr = {1, 2, 3, 5, 7, 6, 4, 2, 1};
    ListNode* head = ArrToLL(arr);

    cout<<"Original Linked List: "<<endl;
    displayLL(head);

    head = removeElements(head, 1);

    cout<<"\nLinked List after deleting elements: "<<endl;
    displayLL(head);

    return 0;
}