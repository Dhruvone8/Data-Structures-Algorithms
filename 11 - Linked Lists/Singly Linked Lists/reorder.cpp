// Leetcode Link: https://leetcode.com/problems/reorder-list/description

#include <bits/stdc++.h>
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

ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;

    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

void reorderList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    // Find Middle of the Linked List
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the LinkedList
    ListNode *second = reverseList(slow->next);

    slow->next = nullptr;

    // Merge both halves
    ListNode* first = head;

    while(second) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;
        
        first = temp1;
        second = temp2;
    }
}