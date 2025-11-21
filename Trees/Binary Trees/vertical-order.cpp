// Leetcode Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    // Take a data Structure
    // That stores the current Vertical Column -> Level / Row in the current column -> Nodes in the the current row

    unordered_map<int, unordered_map<int, multiset<int>>> nodes;

    // Take a queue to store the node and its position (column and row)

    queue<pair<TreeNode *, pair<int, int>>> q;

    // Push the root node into the queue
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto currNode = q.front();
        q.pop();

        // Extract the node from the currNode
        TreeNode *node = currNode.first;

        // Extract the column and row from of the currNode
        int x = currNode.second.first;
        int y = currNode.second.second;

        // Insert the values inside the data structure (nodes)
        nodes[x][y].insert(node->val);

        if (node->left != nullptr)
        {
            q.push({node->left, {x - 1, y + 1}});
        }

        if (node->right != nullptr)
        {
            q.push({node->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;

    // Insert all the columns and sort them
    vector<int> cols;
    for (auto &p : nodes)
    {
        cols.push_back(p.first);
    }

    sort(cols.begin(), cols.end());

    for (int colKey : cols)
    {
        vector<int> cols;
        vector<int> rows;

        // Insert all rows from the current column and sort them
        for (auto &q : nodes[colKey])
        {
            rows.push_back(q.first);
        }

        sort(rows.begin(), rows.end());

        // Insert all the node values
        for (int rowKey : rows)
        {
            cols.insert(cols.end(), nodes[colKey][rowKey].begin(), nodes[colKey][rowKey].end());
        }

        ans.push_back(cols);
    }

    return ans;
}