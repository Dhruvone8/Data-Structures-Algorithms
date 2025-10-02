// Insert a new Node before the given Node

#include<iostream>
#include<vector>
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

void insert_before_node(int NodeVal, ListNode* node)
{
    ListNode* prevNode = node->prev;
    ListNode* newNode = new ListNode(NodeVal, node, prevNode);
    prevNode->next = newNode;
    node->prev = newNode;
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
    vector<int> arr = {10, 30, 40, 50};
    ListNode* head = create_DLL(arr);

    cout<<"Linked List befiore inserting new Node: "<<endl;
    displayLL(head);

    insert_before_node(20, head->next);
    
    cout<<"\nLinked List after inserting new Node: "<<endl;
    displayLL(head);

    return 0;
}