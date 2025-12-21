// GFG Link: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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

vector<int> leftView(Node *root)
{
    vector<int> ans;

    if(root == nullptr)
    {
        return ans;
    }

    queue<pair<Node*, int>> q;
    map<int, int> mpp;

    q.push({root, 0});

    while(!q.empty())
    {
        auto it = q.front();
        Node* currNode = it.first;
        q.pop();
        int currLevel = it.second;

        if(mpp.find(currLevel) == mpp.end())
        {
            mpp[currLevel] = currNode->data;
        }

        if(currNode->left != nullptr)
        {
            q.push({currNode->left, currLevel + 1});
        }

        if(currNode->right != nullptr)
        {
            q.push({currNode->right, currLevel + 1});
        }
    }

    for(auto it : mpp)
    {
        ans.push_back(it.second);
    }

    return ans;
}