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

ListNode *removeMiddle(ListNode *head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    fast = fast->next->next;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* midNode = slow->next;
    slow->next = slow->next->next;

    delete midNode;
    return head;
}