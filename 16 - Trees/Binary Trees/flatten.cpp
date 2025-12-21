// Leetcode Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default Constructor
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with only data
    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with data and left, right nodes
    TreeNode(int data, TreeNode *leftNode, TreeNode *rightNode)
    {
        val = data;
        left = leftNode;
        right = rightNode;
    }
};

void flatten(TreeNode* root) 
{
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* curr = nullptr;

    while(!st.empty())
    {
        curr = st.top();
        st.pop();

        if(curr->right != nullptr)
        {
            st.push(curr->right);
        }

        if(curr->left != nullptr)
        {
            st.push(curr->left);
        }

        if(!st.empty())
        {
            curr->right = st.top();
        }

        curr->left = nullptr;
    }
}

// Morris Traversal
void flatten(TreeNode* root) 
{
    TreeNode* curr = root;
    TreeNode* prev = nullptr;

    while(curr != nullptr)
    {
        if(curr->left != nullptr)
        {
            prev = curr->left;
            while(prev->right != nullptr)
            {
                prev = prev->right;
            }

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}