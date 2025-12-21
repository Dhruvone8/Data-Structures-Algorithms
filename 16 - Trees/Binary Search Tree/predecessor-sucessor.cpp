// GFG Link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* inorderSuccessor(Node* root, int key)
{
    Node* successor = nullptr;

    while(root != nullptr)
    {
        if(root->data > key)
        {
            successor = root;
            root = root->left;
        }

        else
        {
            root = root->right;
        }
    }

    return successor;
}

Node* inorderPredessor(Node* root, int key)
{
    Node* predessor = nullptr;

    while(root != nullptr)
    {
        if(root->data < key)
        {
            predessor = root;
            root = root->right;
        }

        else
        {
            root = root->left;
        }
    }

    return predessor;
}

vector<Node*> findPreSuc(Node* root, int key) 
{
    Node* predecessor = inorderPredessor(root, key);
    Node* successor = inorderSuccessor(root, key);

    return {predecessor, successor};
}
