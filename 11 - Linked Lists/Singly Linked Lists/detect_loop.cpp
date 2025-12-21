// Return true if there is a loop in the Linked List

#include<iostream>
#include<vector>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode* next;

    ListNode(int data)
    {
        val = data;
        next = nullptr;
    }

    ListNode(int data, ListNode* nextptr)
    {
        val = data;
        next = nextptr;
    }
};

bool hasCycle(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = first;

    cout << hasCycle(first);

    return 0;
}