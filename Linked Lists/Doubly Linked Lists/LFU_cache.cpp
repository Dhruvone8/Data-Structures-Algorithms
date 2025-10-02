#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int key;
    int value;
    int count;
    Node *prev;
    Node *next;

    Node(int index, int data)
    {
        key = index;
        value = data;
        count = 1;
    }
};

class DLL
{
public:
    int size;
    Node *head;
    Node *tail;

    DLL()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void insertNode(Node *newNode) // Function to insert node at the front
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }

    void deleteNode(Node *delNode) // Function to remove a node
    {
        Node *delnext = delNode->next;
        Node *delprev = delNode->prev;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache
{
public:
    int cap;
    int currSize;
    int minFreq;
    unordered_map<int, DLL *> freqListMap;
    unordered_map<int, Node *> keyNode;

    LFUCache(int capacity)
    {
        cap = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->count]->deleteNode(node);

        if (node->count == minFreq && freqListMap[node->count]->size == 0)
        {
            minFreq++;
        }

        DLL* nextHigherFreqList = new DLL();
        if(freqListMap.find(node->count + 1) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->count + 1];
        }

        node->count++;
        nextHigherFreqList->insertNode(node);
        freqListMap[node->count] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if(cap == 0)
        {
            return;
        }

        if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);            
        }

        else
        {
            if(currSize == cap)
            {
                DLL* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                currSize--;
            }

            currSize++;
            minFreq = 1;
            DLL* ListFreq = new DLL();
            if(freqListMap.find(minFreq) != freqListMap.end())
            {
                ListFreq = freqListMap[minFreq]; 
            }

            Node* node = new Node(key, value);
            ListFreq->insertNode(node);
            keyNode[key] = node;
            freqListMap[minFreq] = ListFreq;
        }
    }
};