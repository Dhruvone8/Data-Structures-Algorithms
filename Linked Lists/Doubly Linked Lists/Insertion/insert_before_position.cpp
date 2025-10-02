// Given a k position, insert the new node before it

#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode* prev;

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

ListNode* insert_before_kth_position(ListNode* head, int NodeVal, int k)
{
    if(k == 1)
    {
        return insert_before_head(head, NodeVal);
    }

    ListNode* temp = head;
    int count = 0;

    while(temp!= NULL)
    {
        count++;
        if(k == count)
        {
            ListNode* back = temp->prev;
            ListNode* newNode = new ListNode(NodeVal, temp, back);
            back->next = newNode;
            temp->prev = newNode;
        }
        temp = temp->next;
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
    vector<int> arr = {10, 20, 40, 50};
    ListNode* head = create_DLL(arr);

    cout<<"Linked List before inserting new Node: "<<endl;
    displayLL(head);

    head = insert_before_kth_position(head, 30, 3);
    cout<<"\nLinked List After Inserting new Node: "<<endl;
    displayLL(head);

    return 0;
}