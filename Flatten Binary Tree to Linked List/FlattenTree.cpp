#include <iostream>
#include <algorithm>
using namespace std;

// Structure of a node of the binary tree
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

void FlattenTree(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    while (root)
    {
        if (root->left != NULL)
        {
            TreeNode* l = root->left;
            while (l->right != NULL)
            {
                l = l->right;
            }
            l->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
        else
        {
            root = root->right;
        }
    }
}