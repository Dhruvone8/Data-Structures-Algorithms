// Leetcode Link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/

#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level; // To store all node values in the current level

        for (int i = 0; i < size; i++)
        {
            TreeNode *currNode = q.front(); // Store address of current node to push its left and right child in the queue
            q.pop();                        // Remove the currNode

            if (currNode->left != nullptr)
            {
                q.push(currNode->left);
            }

            if (currNode->right != nullptr)
            {
                q.push(currNode->right);
            }

            level.push_back(currNode->val);
        }

        ans.push_back(level);
    }

    return ans;
}