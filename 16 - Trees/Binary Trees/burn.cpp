// GFG Link: https://www.geeksforgeeks.org/problems/burning-tree/1
// Leetcode Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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

// Intuition:
// Start traversing from start node and find distance of each find from the start node
// The maximum distance will be the answer

// Keep track of the parent node to traverse upwards
void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &track_parent)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *currNode = q.front();
        q.pop();

        if (currNode->left != nullptr)
        {
            track_parent[currNode->left] = currNode;
            q.push(currNode->left);
        }

        if (currNode->right != nullptr)
        {
            track_parent[currNode->right] = currNode;
            q.push(currNode->right);
        }
    }
}


// Function to find Node with the start value
TreeNode *inorder(TreeNode *root, int start)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    // Search in left subtree
    TreeNode *left = inorder(root->left, start);
    if (left != nullptr)
    {
        return left;
    }

    // Check current node
    if (root->val == start)
    {
        return root;
    }

    // Search in right subtree
    return inorder(root->right, start);
}

int amountOfTime(TreeNode *root, int start)
{
    unordered_map<TreeNode *, TreeNode *> track_parent;
    markParent(root, track_parent);

    queue<TreeNode *> q;
    unordered_map<TreeNode *, bool> visited;

    // Node that has start value
    TreeNode *startNode = inorder(root, start);

    q.push(startNode);
    visited[startNode] = true;

    int maxdist = 0;

    while(!q.empty())
    {
        int size = q.size();

        for(int i = 0; i < size; i++)
        {
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode->left != nullptr && visited[currNode->left] != true)
            {
                q.push(currNode->left);
                visited[currNode->left] = true;
            }

            if(currNode->right != nullptr && visited[currNode->right] != true)
            {
                q.push(currNode->right);
                visited[currNode->right] = true;
            }

            if(track_parent[currNode] != nullptr && visited[track_parent[currNode]] != true)
            {
                q.push(track_parent[currNode]);
                visited[track_parent[currNode]] = true;
            }
        }

        maxdist++;
    }

    return maxdist -1;
}