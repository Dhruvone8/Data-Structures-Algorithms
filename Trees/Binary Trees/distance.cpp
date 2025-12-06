// Leetcode Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

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

// Mark Parents of the nodes while traversing
void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &track_parent, TreeNode* target)
{
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode* currNode = q.front();
        q.pop();

        if(currNode->left)
        {
            track_parent[currNode->left] = currNode; 
            q.push(currNode->left);
        }

        if(currNode->right)
        {
            track_parent[currNode->right] = currNode; 
            q.push(currNode->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
{
    unordered_map<TreeNode*, TreeNode*> track_parent;
    markParents(root, track_parent, target);

    // Hashmap to store the visited nodes 
    unordered_map<TreeNode*, bool> visited;

    queue<TreeNode*> q;

    // Start traversing radially up and down from the target node to find nodes which are at a distance k from target node

    // Push the target node into the queue
    q.push(target);
    
    // Mark it visited
    visited[target] = true;

    int dist = 0;

    while(!q.empty())
    {
        int size = q.size();
        if(dist == k)
        {
            break;
        }

        dist++;

        for(int i = 0; i < size; i++)
        {
            TreeNode* currNode = q.front();
            q.pop();

            // If the left node exists and it is not yet visited, push it inside the queue and mark it visited
            if(currNode->left != nullptr && visited[currNode->left] != true)
            {
                q.push(currNode->left);
                visited[currNode->left] = true;
            }

            // If the right node exists and it is not yet visited, push it inside the queue and mark is visited
            if(currNode->right != nullptr && visited[currNode->right] != true)
            {
                q.push(currNode->right);
                visited[currNode->right] = true;
            }

            // If parent of currNode exists and it is not yet visited, push it inside the queue and mark it visited
            if(track_parent[currNode] != nullptr && visited[track_parent[currNode]] != true)
            {
                q.push(track_parent[currNode]);
                visited[track_parent[currNode]] = true;
            }
        }
    }

    vector<int> ans;
    while(!q.empty())
    {
        TreeNode* currNode = q.front();
        q.pop();
        ans.push_back(currNode->val);
    }

    return ans;
}