// Leetcode Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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

class BSTIterator
{
    stack<TreeNode *> st;
    bool reverse = true;

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        if (!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != nullptr)
        {
            if (!reverse)
                node = node->left;
            else
                node = node->right;
        }
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (root == nullptr)
            return false;

        BSTIterator left(root, false);
        BSTIterator right(root, true);

        int i = left.next();
        int j = right.next();

        while(i < j)
        {
            if(i + j == k) return true;

            if(i + j < k) i = left.next();

            else j = right.next();
        }

        return false;
    }
};