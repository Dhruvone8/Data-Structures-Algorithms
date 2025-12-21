// Leetcode Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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

TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    if(root == nullptr) return new TreeNode(val);

    TreeNode* temp = root;

    while(true)
    {
        if(temp->val < val)
        {
            if(temp->right != nullptr)
            {
                temp = temp->right;
            }

            else
            {
                temp->right = new TreeNode(val);
                break;
            }
        }

        if(temp->val > val)
        {
            if(temp->left != nullptr)
            {
                temp = temp->left;
            }

            else
            {
                temp->left = new TreeNode(val);
                break;
            }
        }
    }
    
    return root;
}