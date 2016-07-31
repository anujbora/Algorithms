#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/**
 *  Time Complexity : O(1) average case for hasNext() and next()
 *  Space Complexity : O(h) where h is the height of the tree
 */

/**
 *  BSTIterator will be called like this:
 *  BSTIterator i = BSTIterator(root);
 *  while (i.hasNext()) cout << i.next();
 */

/**
 *  Definition for binary tree
 */
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator 
{
private:
    stack<TreeNode*> s;

public: 
    BSTIterator(TreeNode *root) 
    {
        while (root != NULL) 
        {
            s.push(root);
            root = root->left;
        }
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
        TreeNode* node = s.top();
        s.pop();
        if (node->right) 
        {
            TreeNode* temp = node->right;
            while (temp) 
            {
                s.push(temp);
                temp = temp->left;
            }
        }
        return node->val;
    }
};