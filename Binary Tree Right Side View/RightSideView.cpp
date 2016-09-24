#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

// Structure of a node of the binary tree
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root, vector<int>& result, int level) 
{
    if (root == NULL)
    {
        return;
    }
    
    if (result.size() < level)
    {
        result.push_back(root->data);
    }

    dfs(root->right, result, level + 1);
    dfs(root->left, result, level + 1);
}

vector<int> RightSideView(TreeNode* root)
{
    vector<int> result;

    dfs(root, result, 1);

    return result;
}