// Leetcode Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <bits/stdc++.h>
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

TreeNode *createTree(vector<int> &nums, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;

    TreeNode *root = new TreeNode(nums[mid]);

    root->left = createTree(nums, start, mid - 1);
    root->right = createTree(nums, mid + 1, end);

    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    TreeNode *root = createTree(nums, 0, nums.size() - 1);
    return root;
}

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);

    return 0;
}