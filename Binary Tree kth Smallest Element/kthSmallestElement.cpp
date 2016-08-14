#include <iostream>
#include <algorithm>
using namespace std;

/**
 *  Time Complexity = O(nlogn)
 */

// Structure of a node of the binary tree
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

int count(TreeNode* n)
{
    if (n == NULL)
    {
        return 0;
    }
    
    return 1 + count(n->left) + count(n->right);
}

int kthSmallest(TreeNode* root, int k) 
{
    int nodes = count(root->left);
    
    if (k <= nodes)
    {
        return kthSmallest(root->left, k);
    }
    
    else if (k > (nodes + 1))
    {
        return kthSmallest(root->right, k - 1 - nodes);
    }

    return root->data;
}