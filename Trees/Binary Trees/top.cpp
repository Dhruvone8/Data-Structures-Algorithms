// GFG Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// To get the top view of a binary tree, use vertical order traversal and add the first node from each vertical column
vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }

    // This map stores the vertical line number and the first node seen in it
    map<int, int> mpp;

    // This queue stores the Node and the vertical line number in which it is present
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        Node* currNode = it.first;
        q.pop();
        int currCol = it.second;

        // If the map didn't stored the currCol and its value, push the value and node in the map
        if (mpp.find(currCol) == mpp.end())
        {
            mpp[currCol] = currNode->data;
        }

        if (currNode->left != nullptr)
        {
            q.push({currNode->left, currCol - 1});
        }

        if (currNode->right != nullptr)
        {
            q.push({currNode->right, currCol + 1});
        }
    }
    
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }

    return ans;
}