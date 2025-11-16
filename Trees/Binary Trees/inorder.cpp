// Leetcode Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

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

// Recursive Approach
void inorder(vector<int> &ans, TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(ans, root->left);
    ans.push_back(root->val);
    inorder(ans, root->right);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder(ans, root);
    return ans;
}

// Iterative Approach
vector<int> inordertravsersal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *node = root;

    while (!st.empty() || node != nullptr)
    {
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }

        else
        {
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }

    return ans;
}