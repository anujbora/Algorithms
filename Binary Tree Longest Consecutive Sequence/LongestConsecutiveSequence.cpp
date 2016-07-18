#include <iostream>
#include <algorithm>
using namespace std;

/*
 *  Time Complexity : O(n); where n is the number of nodes in binary tree
 *  Space Complexity : O(1)
 */

// Structure of a node of the binary tree
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

int result = 0;

void helper(TreeNode* root, int target, int curr)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data == target)
    {
        curr++;
    }
    else
    {
        curr = 1;
    }

    result = max(curr, result);

    helper(root->left, target + 1, curr);
    helper(root->right, target + 1, curr);
}

int LongestConsecutiveSequence(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    helper(root, root->data, 0);

    return result;
}