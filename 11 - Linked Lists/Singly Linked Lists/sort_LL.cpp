// Using Merge Sort

#include <iostream>
#include <vector>
#include <algorithm>
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

ListNode *ArrToLL(vector<int> arr)
{
    if (arr.size() == 0)
    {
        return nullptr;
    }

    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        mover->next = new ListNode(arr[i]);
        mover = mover->next;
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

ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *mergeList(ListNode *List1, ListNode *List2)
{
    if (List1 == NULL)
    {
        return List2;
    }

    if (List2 == NULL)
    {
        return List1;
    }

    ListNode *result;

    if (List1->val > List2->val)
    {
        result = List2;
        result->next = mergeList(List1, List2->next);
    }

    else
    {
        result = List1;
        result->next = mergeList(List1->next, List2);
    }

    return result;
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *middle = findMiddle(head);
    ListNode *right = middle->next;
    middle->next = nullptr;
    ListNode *left = head;

    left = sortList(left);
    right = sortList(right);

    return mergeList(left, right);
}

int main()
{
    vector<int> arr = {4, 19, 14, 5, -3, 1, 8, 5, 11, 15};
    ListNode *head = ArrToLL(arr);

    cout << "Original Linked List: " << endl;
    displayLL(head);

    head = sortList(head);

    cout << "\nSorted Linked List: " << endl;
    displayLL(head);

    return 0;
}