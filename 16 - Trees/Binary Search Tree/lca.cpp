// Leetcode Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if(root == nullptr) return root;

    if(root->val > p->val && root->val > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    else if(root->val < p->val && root->val < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}