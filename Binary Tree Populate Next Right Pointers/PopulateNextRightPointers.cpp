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
    struct TreeNode* next;
    TreeNode(int val) : data(val), left(NULL), right(NULL), next(NULL) {}
};

void PopulateNextRightPointers(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    // head keeps tracks of first node on the next level
    TreeNode* head = NULL;
    // prev keeps track of the previous node on the next level
    TreeNode* prev = NULL;

    while (root != NULL)
    {
        while(root != NULL)
        {
            if (root->left != NULL)
            {
                if (prev == NULL)
                {
                    head = root->left;
                }
                else
                {
                    prev->next = root->right;
                }
                prev = root->left;
            }

            if (root->right != NULL)
            {
                if (prev == NULL)
                {
                    head = root->right;
                }
                else
                {
                    prev->next = root->right;
                }
                prev = root->right;
            }

            root = root->next;
        }

        root = head;
        head = NULL;
        prev = NULL;
    }
}