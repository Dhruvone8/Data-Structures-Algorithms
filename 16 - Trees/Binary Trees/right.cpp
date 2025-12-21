// Leetcode Link: https://leetcode.com/problems/binary-tree-right-side-view/description/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

vector<int> rightSideView(TreeNode* root) 
{
    vector<int> ans;
    if(root == nullptr)
    {
        return ans;
    }

    // Store node and its level inside queue
    queue<pair<TreeNode*, int>> q;

    // Store the level and the value at this level inside the map data structure
    map<int, int> mpp;
    
    q.push({root, 0});

    while(!q.empty())
    {
        auto it = q.front();
 
        TreeNode* currNode = it.first;
        q.pop();

        int currLevel = it.second;

        mpp[currLevel] = currNode->val;

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