// Return the node from where the loop starts, if there is no loop return NULL

/* 
Approach:
Detect if there is a loop
If yes, find the starting point
*/

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

ListNode* detectCycle(ListNode *head) 
{
    // Detect the Loop
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            
            return slow;
        }
    }

    return NULL;
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
    fourth->next = third;

    ListNode* head = detectCycle(first);
    cout<<head->val;

    return 0;
}