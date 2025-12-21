// Leetcode Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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

TreeNode* helper(vector<int> &preorder, int &i, int lower_bound, int upper_bound)
{   
    if(i == preorder.size() || (preorder[i] < lower_bound || preorder[i] > upper_bound)) return nullptr;

    TreeNode* root = new TreeNode(preorder[i]);
    i++;

    root->left = helper(preorder, i, lower_bound, root->val);
    root->right = helper(preorder, i, root->val, upper_bound);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) 
{
    int i = 0;
    return helper(preorder, i, INT32_MIN, INT32_MAX);   
}