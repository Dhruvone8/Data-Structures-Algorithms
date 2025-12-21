#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;

        Node(int index, int data)
        {
            key = index;
            value = data;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node *> mp;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode)
    {
        Node* delprev = delNode->prev;
        Node* delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        if(mp.find(key) != mp.end())    // If the node is present
        {
            Node* node = mp[key];
            int val = node->value;
            deleteNode(node);
            insertNode(node);
            return val;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end())    // If the node already exists
        {
            Node* existingNode = mp[key];
            existingNode->value = value;
            deleteNode(existingNode);
            insertNode(existingNode);
        }
        else
        {
            if(mp.size() == cap)    // If size of the Linked List is full
            {
                Node* node = tail->prev;
                mp.erase(node->key);
                deleteNode(node);
                delete node;
            }

            Node* node = new Node(key, value);
            mp[key] = node;
            insertNode(node);
        }
    }
};