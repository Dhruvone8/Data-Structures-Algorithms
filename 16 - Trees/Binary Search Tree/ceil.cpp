// GFG Link: https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

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

int findCeil(Node *root, int x)
{
    int ceil = -1;

    while(root != nullptr)
    {
        if(root->data == x)
        {
            return x;
        }

        else if(root->data > x)
        {
            ceil = root->data;
            root = root->left;
        }

        else if(root->data < x)
        {
            root = root->right;
        }
    }

    return ceil;
}

int main() {

    // Constructing the tree in the image
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);

    root->left->right = new Node(2);
    root->left->right->right = new Node(3);

    int x = 3;
    int result = findCeil(root, x);

    cout << "Ceil of " << x << " is: " << result << endl;

    return 0;
}