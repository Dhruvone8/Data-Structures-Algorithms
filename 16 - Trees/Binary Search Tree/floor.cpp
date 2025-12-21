// GFG Link: https://www.geeksforgeeks.org/problems/floor-in-bst/1

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int floor(Node* root, int x) 
{
    int floor = -1;
    while(root != nullptr)
    {
        if(root->data == x)
        {
            return x;
        }

        else if(root->data > x)
        {
            root = root->left;
        }

        else if(root->data < x)
        {
            floor = root->data;
            root = root->right;
        }
    }

    return x;
}