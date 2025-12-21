// Leetcode Link: https://leetcode.com/problems/validate-binary-search-tree/

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

bool isValid(TreeNode* root, int min_range, int max_range)
{
    if(root == nullptr) return true;

    if(root->val > max_range || root->val < min_range) return false;

    return isValid(root->left, min_range, root->val) && isValid(root->right, root->val, max_range);
}

bool isValidBST(TreeNode *root)
{
   return isValid(root, INT32_MIN, INT32_MAX);
}