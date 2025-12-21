// Leetcode Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

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

// Recursive Approach
void inorder(vector<int> &ans, TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(ans, root->left);
    ans.push_back(root->val);
    inorder(ans, root->right);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder(ans, root);
    return ans;
}

// Iterative Approach
vector<int> inordertravsersal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *node = root;

    while (!st.empty() || node != nullptr)
    {
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }

        else
        {
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }

    return ans;
}

// Morris Traversal
vector<int> morrisInorderTraversal(TreeNode* root)
{
    vector<int> inorder;
    TreeNode* curr = root;

    while(curr != nullptr)
    {
        if(curr->left == nullptr)
        {
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        
        else
        {
            TreeNode* prev = curr->left;
            while(prev->right != nullptr && prev->right != curr)
            {
                prev = prev->right;
            }

            
            if(prev->right == nullptr)
            {
                prev->right = curr;
                curr = curr->left;
            }

            else if(prev->right == curr)
            {
                prev->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->right = new TreeNode(6);

    vector<int> ans = morrisInorderTraversal(root);

    cout << "Morris Inorder Traversal: ";
    for(int x : ans)
        cout << x << " ";

    cout << endl;
    return 0;
}