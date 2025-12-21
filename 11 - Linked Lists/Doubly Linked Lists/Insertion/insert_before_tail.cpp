// Insert the node given before the tail

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

ListNode *insert_before_head(ListNode *head, int nodeVal)
{
    if (head == NULL) // Empty Linked List
    {
        return new ListNode(nodeVal);
    }

    ListNode *temp = new ListNode(nodeVal, head, nullptr);
    head->prev = temp;
    return temp;
}

ListNode *insert_before_tail(ListNode *head, int NodeVal)
{
    if (head == NULL)
    {
        return new ListNode(NodeVal);
    }

    if (head->next == nullptr) // Inly one node in the Linked List
    {
        return insert_before_head(head, NodeVal);
    }

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    ListNode *back = temp->prev;
    ListNode *newNode = new ListNode(NodeVal, temp, back);
    temp->prev = newNode;
    back->next = newNode;

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
    vector<int> arr = {10, 20, 30, 50};
    ListNode *head = create_DLL(arr);

    cout << "Linked List before adding new Node: " << endl;
    displayLL(head);

    head = insert_before_tail(head, 40);
    cout << "\nLinked List after adding new Node: " << endl;
    displayLL(head);

    return 0;
}