// Leetcode Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }

    queue<TreeNode *> q;
    q.push(root);
    int flag = 0; // Flag = 0 indicates that traversal is from Left -> Right and Flag = 1 indicates that travsersal is from Right -> Left

    while (!q.empty())
    {
        int s = q.size();
        vector<int> level; // To store the elements of current level

        for (int i = 0; i < s; i++)
        {
            TreeNode *currNode = q.front();
            q.pop();

            level.push_back(currNode->val);

            if (currNode->left != nullptr)
            {
                q.push(currNode->left);
            }

            if (currNode->right != nullptr)
            {
                q.push(currNode->right);
            }
        }

        if (flag == 1)
        {
            reverse(level.begin(), level.end());
        }

        ans.push_back(level);

        flag = flag ^ 1;
    }

    return ans;
}
