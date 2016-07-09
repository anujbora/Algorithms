#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Structure of a node of the bianry tree
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

void calculateHorizontalDistance(TreeNode* root, unordered_map<int, vector<int> > &hash, int hd)
{
    if(root == NULL)
    {
        return;
    }

    hash[hd].push_back(root->data);

    calculateHorizontalDistance(root->left, hash, hd-1);
    calculateHorizontalDistance(root->right, hash, hd+1);
}

vector<vector<int> > binaryTree_columns(TreeNode* root) 
{
    vector<vector<int> > result;
    
    unordered_map<int, vector<int> > hash;

    calculateHorizontalDistance(root, hash, 0);

    for(pair<int, vector<int> > p : hash)
    {
        result.push_back(p.second);
    }

    return result;
}