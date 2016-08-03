#include <vector>
#include <queue>
using namespace std;

// Structure of a node of the bianry tree
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int data) : val(data), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> grid;
    
    if (root == NULL)
    {    
        return grid;
    }

    vector<int> row;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* node;
    int size=0;
    
    while(!q.empty())
    {
        size = q.size();
        
        while(size)
        {
            node = q.front();
            q.pop();
            if(node->left != NULL)
            {    
                q.push(node->left);
            }
            if(node->right != NULL)
            {
                q.push(node->right);
            }
            row.push_back(node->val);
            size--;
        }
        
        grid.push_back(row);
        row.clear();
    }
    return grid;
}