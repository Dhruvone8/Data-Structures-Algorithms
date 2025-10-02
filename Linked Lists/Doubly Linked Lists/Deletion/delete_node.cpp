// Delete the node given

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
void deletenode(ListNode *temp)
{
    ListNode *nextelement = temp->next;
    ListNode *prevelement = temp->prev;

    if (nextelement == NULL)
    {
        prevelement->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }

    prevelement->next = nextelement;
    nextelement->prev = prevelement;

    temp->next = nullptr;
    temp->prev = nullptr;

    delete temp;
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

    cout << "Linked List Before Deleting the Node: " << endl;
    displayLL(head);

    deletenode(head->next);

    cout << "\nLinked List Before Deleting the Node: " << endl;
    displayLL(head);

    return 0;
}