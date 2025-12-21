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

ListNode *reverse_LL(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode *findKthNode(ListNode *temp, int k)
{
    k--;
    while (temp != NULL && k != 0)
    {
        k--;
        temp = temp->next;
    }

    return temp;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *prevNode = nullptr;

    while (temp != NULL)
    {
        ListNode *kthNode = findKthNode(temp, k);

        if (kthNode == NULL) // If there is no Kth Node
        {
            if (prevNode != NULL) // Check If prevNode is not NULL i.e the Linked List has elements less than k
            {
                prevNode->next = temp; // Attach the remaining elements with the Linked List
            }

            break;
        }
        
        ListNode *next = kthNode->next; // Preserve the next node before breaking out the Linked List

        kthNode->next = nullptr; // Break the Linked List

        ListNode *newHead = reverse_LL(temp);

        if (temp == head) // Its the first k group, so head must be updated
        {
            head = kthNode;
        }
        else
        {
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = next;
    }

    return head;
}

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

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = ArrToLL(arr);

    cout << "Original Linked List: " << endl;
    displayLL(head);

    head = reverseKGroup(head, 2);

    cout << "\nModified Linked List: " << endl;
    displayLL(head);

    return 0;
}