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

TreeNode* invertTreeIterative(TreeNode* root)
{
    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode* temp = s.top();
        s.pop();

        if (temp != NULL)
        {
            s.push(temp->left);
            s.push(temp->right);
            swap(temp->left, temp->right);
        }
    }

    return root;
}

TreeNode* invertTreeRecursive(TreeNode* root) 
{
    if (root == NULL)
    {
        return root;
    }

    TreeNode* temp = root->left;
    root->left = invertTreeRecursive(root->right);
    root->right = invertTreeRecursive(temp);
    
    return root;
}