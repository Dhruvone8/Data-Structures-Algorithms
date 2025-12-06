// Leetcode Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
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

string serialize(TreeNode *root)
{
    if (root == nullptr)
    {
        return "";
    }

    string s = "";
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode *currNode = q.front();
        q.pop();

        if (currNode == nullptr)
        {
            s.append("x,");
        }

        else
        {
            s.append(to_string(currNode->val) + ",");
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    
    return s;
}

TreeNode *deserialize(string data)
{
    if (data.length() == 0)
    {
        return nullptr;
    }

    stringstream s(data);
    string str;

    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "x")
        {
            node->left = nullptr;
        }
        
        else
        {
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if(str == "x")
        {
            node->right = nullptr;
        }

        else
        {
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}