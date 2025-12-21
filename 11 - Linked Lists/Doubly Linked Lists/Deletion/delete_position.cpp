// Delete kth node from the linked list

#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int data)
    {
        val = data;
        next = nullptr;
        prev = nullptr;
    }

    ListNode(int data, ListNode* nextptr, ListNode* prevptr)
    {
        val = data;
        next = nextptr;
        prev = prevptr;
    }
};

ListNode *delete_head(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    ListNode *temp = head;

    head = head->next;

    head->prev = NULL;
    temp->next = NULL;

    delete temp;

    return head;
}

ListNode *delete_tail(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    ListNode *prev = temp->prev;
    prev->next = NULL;
    temp->prev = NULL;

    delete temp;

    return head;
}

ListNode *delete_kth_node(ListNode *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    int count = 0;
    ListNode *temp = head;

    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }

        temp = temp->next;
    }

    if(temp == NULL)    // K is greater than the count of Linked List
    {
        return NULL;
    }

    ListNode *prevNode = temp->prev;
    ListNode *nextNode = temp->next;

    if (prevNode == NULL && nextNode == NULL)
    {
        return NULL;
    }

    else if (prevNode == NULL) // Head
    {
        return delete_head(head);
    }

    else if (nextNode == NULL) // Tail
    {
        return delete_tail(head);
    }

    else // Node is somewhere in between
    {
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }

    return head;
}

ListNode *create_DLL(vector<int> arr)
{
    ListNode *head = new ListNode(arr[0]); // next and prev points to null currently

    ListNode *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next;
    }

    return head;
}

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
    cout << " -> NULL";
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    ListNode *head = create_DLL(arr);

    cout << "Linked List before deleting the Kth Node: " << endl;
    displayLL(head);

    head = delete_kth_node(head, 3);

    cout<<"\nLinked List after deleting the Kth Node: "<<endl;
    displayLL(head);
    
    return 0;
}