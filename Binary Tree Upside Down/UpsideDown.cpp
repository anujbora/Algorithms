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

TreeNode* UpsideDown(TreeNode* root)
{
    if (root == NULL || root->left == NULL || root->right == NULL)
    {
        return root;
    }

    TreeNode* curr = root;
    TreeNode* prev = NULL;
    TreeNode* next = NULL;
    TreeNode* temp = NULL;

    while (curr != NULL)
    {
        next = curr->left;
        curr->left = temp;
        temp = curr->right;
        curr->right = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}