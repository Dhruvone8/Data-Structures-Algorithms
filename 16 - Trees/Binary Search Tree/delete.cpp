// Leetcode Link: https://leetcode.com/problems/delete-node-in-a-bst/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* findLastRight(TreeNode* root)
{
    if(root->right == nullptr)
    {
        return root;
    }

    return findLastRight(root->right);
}

TreeNode* helper(TreeNode* root)
{
    // If the left part doesn't exist then connect the right child of the deleted node to the parent of the root
    if(root->left == nullptr)
    {
        return root->right;
    }

    // Else if right part doesn't exist then connect the left child
    else if(root->right == nullptr)
    {
        return root->left;
    }

    TreeNode* rightChild = root->right;     
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key) 
{
    if(root == nullptr)
    {
        return nullptr;
    }
    
    // If root node is to be deleted
    if(root->val == key)
    {
        return helper(root);
    }

    TreeNode* temp = root;

    while(temp != nullptr)
    {
        // If Node value is greater than the key
        if(temp->val > key)
        {
            // If left child of the node is not null and the node value is equal to the key
            if(temp->left != nullptr && temp->left->val == key)
            {
                temp->left = helper(temp->left);
                break;
            }

            // Else move to the left
            else
            {
                temp = temp->left;
            }
        }

        else if(temp->val < key)
        {
            if(temp->right != nullptr && temp->right->val == key)
            {
                temp->right = helper(temp->right);
                break;
            }

            else
            {
                temp = temp->right;
            }
        }
    }

    return root;
}