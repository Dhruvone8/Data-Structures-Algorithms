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

int length_of_loop(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    int count = 0;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            fast = fast->next;
            count++; 
            
            while(fast != slow)
            {
                fast = fast->next;
                count++;
            }

            return count;
        }
    }
    
    return 0;
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
    fourth->next = fifth;
    fifth->next = second;

    cout << length_of_loop(first);

    return 0;
}