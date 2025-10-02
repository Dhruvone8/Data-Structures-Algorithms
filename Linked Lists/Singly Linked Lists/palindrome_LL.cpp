// Check if a Linked List is Palindrome

// Approach:

/*
Find the middle of the Linked List
Reverse the second half
Traverse both the Halves and check the values are equal or not
Return True if Equal and False if not
*/

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

bool isPalindrome(ListNode *head)
{
    // Find the Middle
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse Second Half
    ListNode* newHead = reverseList(slow->next);

    // Compare both Halves
    ListNode* firstHead = head;
    ListNode* secondHead = newHead;

    while(secondHead != NULL)
    {
        if(firstHead->val != secondHead->val)
        {
            reverseList(newHead);   // Change the List Back to its original form
            return false;
        }

        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    
    reverseList(newHead);      // Change the List Back to its original form
    return true;
}

int main()
{
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(2);
    ListNode* fourth = new ListNode(1);

    first->next = second;
    second->next = third;
    third->next = fourth;

    cout << isPalindrome(first);

    return 0;
}