// Leetcode Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

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
void preorder(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

// Iterative approach using stack
vector<int> preorderTraversal1(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> ans;

    if (root == nullptr)
    {
        return ans;
    }

    st.push(root);

    while (!st.empty())
    {
        TreeNode *currNode = st.top();
        st.pop();

        ans.push_back(currNode->val);

        if (currNode->right != nullptr)
        {
            st.push(currNode->right);
        }

        if (currNode->left != nullptr)
        {
            st.push(currNode->left);
        }
    }

    return ans;
}