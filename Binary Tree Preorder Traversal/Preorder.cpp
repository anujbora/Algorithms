#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

/**
 *  Time Complexity = O(n)
 */

// Structure of a node of the binary tree
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> Preorder(TreeNode* root) 
{
    stack<TreeNode*> s;
    TreeNode* p = root;
    vector<int> result;
    while (!s.empty() || p)
    {
        while (p)
        {
            s.push(p);
            result.push_back(p->data);
            p = p->left;
        }

        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }

    return result;
}