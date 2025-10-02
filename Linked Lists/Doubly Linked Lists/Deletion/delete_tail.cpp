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

    ListNode(int data, ListNode *nextptr, ListNode *prevptr)
    {
        val = data;
        next = nextptr;
        prev = prevptr;
    }
};

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
    ListNode* head = create_DLL(arr);

    cout<<"Linked List before deleting the last element: "<<endl;
    displayLL(head);

    head = delete_tail(head);

    cout<<"\nLinked List after deleting the last element: "<<endl;
    displayLL(head);

    return 0;
}