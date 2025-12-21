// Given two sorted Linked Lists, merge them into one sorted Linked List (Uisng Recursion)

#include <iostream>
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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }

    if (list2 == NULL)
    {
        return list1;
    }

    ListNode *result;

    if (list1->val < list2->val)
    {
        result = list1;
        result->next = mergeTwoLists(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = mergeTwoLists(list1, list2->next);
    }

    return result;
}

void printLinkedList(ListNode *head)
{
    ListNode *temp = head; // Temporary pointer to traverse the list

    while (temp != nullptr)
    {
        cout << temp->val;
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
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode *mergedList = mergeTwoLists(list1, list2);

    cout << "Merged Sorted Linked List:" << endl;
    printLinkedList(mergedList);

    return 0;
}