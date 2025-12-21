// Leetcode Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <iostream>
#include <vector>
#include <stack>
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    // Base Case
    if(root == nullptr || root == p || root == q)
    {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left == nullptr)
    {
        return right;
    }

    else if(right == nullptr)
    {
        return left;
    }

    else
    {
        return root;
    }
}

int main()
{
    // Manually constructing the binary tree
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // p = 5, q = 1
    TreeNode* p = root->left;      // node with value 5
    TreeNode* q = root->right;     // node with value 1

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if(lca != nullptr)
    {
        cout << "LCA of " << p->val << " and " << q->val << " = " << lca->val << endl;
    }
    else 
    {
        cout << "LCA not found!" << endl;
    }

    return 0;
}
