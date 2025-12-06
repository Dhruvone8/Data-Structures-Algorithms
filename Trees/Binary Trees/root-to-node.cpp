// Given the Root of a tree and a node 
// Find path of the tree from root to the node 

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

bool getPath(TreeNode* root, vector<int> &arr, int x)
{
    // If the node is not yet found and we reached null, return true
    if(root == nullptr)
    {
        return false;
    }

    arr.push_back(root->val);

    // If the value of the current Node is equal to the given node return true
    if(root->val == x)
    {
        return true;
    }

    // Else check left and right
    if(getPath(root->left, arr, x) || getPath(root->right, arr, x))
    {
        return true;
    }

    // If not true, pop back the element while backtracking
    arr.pop_back();
    return false;
}

vector<int> rootToNode(TreeNode* root, int b)
{
    vector<int> path;
    if(root == nullptr)
    {
        return path;
    }

    getPath(root, path, b);
    return path;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int target = 5;

    vector<int> path = rootToNode(root, target);

    // Print the path
    if(path.empty())
    {
        cout << "Node not found in the tree." << endl;
    }
    else
    {
        cout << "Path from root to " << target << ": ";
        for(int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
