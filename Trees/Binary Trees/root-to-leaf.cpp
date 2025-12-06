// Leetcode Link: https://leetcode.com/problems/binary-tree-paths/description/
// GFG Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

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

// Leetcode
void getPath(TreeNode *root, string path, vector<string> &ans)
{
    // If the current Node is a leaf Node
    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(path);
        return;
    }

    // Else check left and right subtrees
    if (root->left)
    {
        getPath(root->left, path + "->" + to_string(root->left->val), ans);
    }

    if (root->right)
    {
        getPath(root->right, path + "->" + to_string(root->right->val), ans);
    }
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    if (root == nullptr)
    {
        return ans;
    }

    string path = to_string(root->val);
    getPath(root, path, ans);

    return ans;
}

// GFG
void getPathGfg(Node *root, vector<int> &path, vector<vector<int>> &ans)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(path);
        return;
    }

    if (root->left)
    {
        path.push_back(root->left->data);
        getPathGfg(root->left, path, ans);
        path.pop_back();
    }

    if (root->right)
    {
        path.push_back(root->right->data);
        getPathGfg(root->right, path, ans);
        path.pop_back();
    }
}

vector<vector<int>> Paths(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }

    vector<int> path;
    path.push_back(root->data);
    getPathGfg(root, path, ans);

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> result = binaryTreePaths(root);

    cout << "Root-to-leaf paths:" << endl;
    for (string s : result)
    {
        cout << s << endl;
    }

    return 0;
}
