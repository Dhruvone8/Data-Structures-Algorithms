// GFG Link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

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

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;

        if(root == nullptr)
        {
            return ans;
        }

        queue<pair<Node *, int>> q;

        map<int, int> mpp;

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *currNode = it.first;
            int currCol = it.second;

            mpp[currCol] = currNode->data;

            if (currNode->left != nullptr)
            {
                q.push({currNode->left, currCol - 1});
            }

            if (currNode->right != nullptr)
            {
                q.push({currNode->right, currCol + 1});
            }
        }

        for(auto it : mpp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};