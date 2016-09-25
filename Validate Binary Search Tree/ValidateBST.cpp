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

bool isValidBST(TreeNode* root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data <= min || root->data >= max)
    {
        return false;
    }

    return isValidBST(root->left, min, root->data) && isValidBST(root->right, root->data, max);
}

bool ValidateBST(TreeNode* root) 
{
    return isValidBST(root, INT_MIN, INT_MAX);
}