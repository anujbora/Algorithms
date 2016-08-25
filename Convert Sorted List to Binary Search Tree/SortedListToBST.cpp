#include <iostream>
#include <algorithm>
using namespace std;

// Structure of a node of singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Structure of a node of the binary tree
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

TreeNode* sortedListToBST(ListNode* head) 
{
    if (head == NULL)
    {
        return NULL;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    TreeNode* root = new TreeNode(slow->val);
        
    if(prev!= NULL)
    {
        prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
        
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    
    return root;
}