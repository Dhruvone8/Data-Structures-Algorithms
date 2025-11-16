// Representation of Binary TreeNode using C++

#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int main()
{
    TreeNode *tree = new TreeNode(1);
    
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);

    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(7);
}