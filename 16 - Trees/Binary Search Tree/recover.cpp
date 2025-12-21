// Leetcode Link: https://leetcode.com/problems/recover-binary-search-tree/

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

class Solution
{
private:
    TreeNode *prev;
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;

public:
    void inorderTravsersal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        // If it's not the first node and there is a violation
        if (!prev && (prev->val > root->val))
        {
            if(first == nullptr)
            {
                first = prev;
                middle = root;
            }

            else 
            {
                last = root;
            }
        }

        prev = root;
        inorderTravsersal(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        first = middle = last = nullptr;
        prev = new TreeNode(INT32_MIN);

        inorderTravsersal(root);

        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};