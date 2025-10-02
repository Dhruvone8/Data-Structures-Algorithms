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
};

ListNode* reverseList(ListNode* head)
{
    ListNode* curr = head;
    ListNode* prev = NULL;

    while(curr != NULL)
    {
        ListNode* next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }

    return prev;
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
    ListNode* first = new ListNode(10);
    ListNode* second = new ListNode(20);
    ListNode* third = new ListNode(30);
    ListNode* fourth = new ListNode(40);
    ListNode* fifth = new ListNode(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout<<"Linked List before Reversing: "<<endl;
    printLinkedList(first);

    ListNode* head = reverseList(first);

    cout<<"Linked List after Reversing: "<<endl;
    printLinkedList(head);

    return 0;
}

