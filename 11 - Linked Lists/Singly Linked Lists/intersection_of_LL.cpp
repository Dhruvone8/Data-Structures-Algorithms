// Find the intersection of two Linked Lists
// Intersection node is the node where the two Linked Lists points to the same Node Address, Not the node with same value

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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *tempA = headA;
    ListNode *tempB = headB;

    int lenA = 0;   
    int lenB = 0;

    while (tempA != NULL)   // Find the length of first Linked List
    {
        lenA++;
        tempA = tempA->next;
    }

    while (tempB != NULL)    // Find the length of second Linked List
    {
        lenB++;
        tempB = tempB->next;
    }

    if(lenA > lenB)     // If First Linked Linked Is larger than Second Linked List
    {
        while(lenA != lenB)     // Move the head of the first Linked List till length of both Linked Lists become equal
        {
            headA = headA->next;
            lenA--;
        }
    }

    if(lenB > lenA)     // If First Linked Linked Is larger than Second Linked List
    {
        while(lenA != lenB)      // Move the head of the first Linked List till length of both Linked Lists become equal
        {
            headB = headB->next;
            lenB--;
        }
    }

    while(headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}

int main()
{
    // Shared part
    ListNode *intersect = new ListNode(8);
    intersect->next = new ListNode(10);

    // List A: 3 -> 7 -> 8 -> 10
    ListNode *headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = intersect;

    // List B: 99 -> 1 -> 8 -> 10
    ListNode *headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = intersect;

    ListNode *result = getIntersectionNode(headA, headB);

    cout << "Intersection at node with value: " << result->val << endl;
    return 0;
}