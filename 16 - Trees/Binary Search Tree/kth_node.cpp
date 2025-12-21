// Leetcode Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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

// Find the inorder of the tree: It is always sorted

int kthSmallest(TreeNode *root, int k)
{
    int count = 0;
    stack<TreeNode *> st;
    vector<int> ans;
    TreeNode* node = root;

    while(!st.empty() || node != nullptr)
    {
        if(node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        
        else
        {
            count++;
            node = st.top();
            st.pop();

            if(count == k)
            {
                return node->val;
            }

            node = node->right;
        }
    }

    return count;
}