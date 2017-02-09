#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// Structure of a node of the binary tree
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

TreeNode *deepest = NULL;
int maxHeight = 0;

void dfs(TreeNode* root, int height)
{
    if (root == NULL)
    {
      return;
    }

    if (height > maxHeight)
    {
      maxHeight = height;
      deepest = root;
    }

    dfs(root->left, height + 1);
    dfs(root->right, height + 1);
}

TreeNode* DeepestNode(TreeNode* root)
{
    dfs(root, 1);
    return deepest;
}
