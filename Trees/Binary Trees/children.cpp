// GFG Link: https://www.geeksforgeeks.org/problems/children-sum-parent/1

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

bool isSumProperty(Node *root)
{
    // Leaf node and null node follows children sum property
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return true;
    }

    // If node is null its value is 0
    int left = 0;
    int right = 0;

    if (root->left != nullptr)
    {
        left = root->left->data;
    }

    if (root->right != nullptr)
    {
        right = root->right->data;
    }

    if (root->data == left + right)
    {
        return isSumProperty(root->left) && isSumProperty(root->right);
    }

    else
    {
        return false;
    }
}

int main()
{
    Node *root = new Node(35);

    root->left = new Node(20);
    root->right = new Node(15);

    root->left->left = new Node(15);
    root->left->right = new Node(5);

    root->right->left = new Node(10);
    root->right->right = new Node(5);

    if (isSumProperty(root))
        cout << "Tree follows Children Sum Property\n";
    else
        cout << "Tree does NOT follow Children Sum Property\n";

    return 0;
}
