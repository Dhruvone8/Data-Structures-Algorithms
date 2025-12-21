// GFG Link: https://www.geeksforgeeks.org/problems/maximum-width-of-tree/1

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

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

// GFG Code

int maxWidth(Node* root) 
{
    if(root == nullptr)
    {
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int maxw = 1;

    while(!q.empty())
    {
        int n = q.size();
        maxw = max(n, maxw);

        while(n != 0)
        {
            Node* currNode = q.front();
            q.pop();
            n--;

            if(currNode->left != nullptr)
            {
                q.push(currNode->left);
            }

            if(currNode->right != nullptr)
            {
                q.push(currNode->right);
            }
        }
    }

    return maxw;
}

// Leetcode 

int widthOfBinaryTree(TreeNode* root) 
{
    if(root == nullptr)
    {
        return 0;
    }

    int ans = 0;

    // Store the node and its index in the queue
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty())
    {
        int size = q.size();

        // Store the min index of each level
        int minI = q.front().second;

        // Store the first and last index of each level
        int first;
        int last;

        for(int i = 0; i < size; i++)
        {
            int currI = q.front().second - minI;
            TreeNode* currNode = q.front().first;
            q.pop();
            if(i == 0)
            {
                first = currI;
            }

            if(i == size - 1)
            {
                last = currI;
            }

            if(currNode->left)
            {
                q.push({currNode->left, (currI * 2) + 1});
            }

            if(currNode->right)
            {
                q.push({currNode->right, (currI * 2) + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}