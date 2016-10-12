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

ListNode* rotateRight(ListNode* head, int k) 
{
    if (head == NULL)
    {
        return head;
    }
    
    int len = 0;
    ListNode* fast = head;
    ListNode* last;

    // Get the length of the linked list
    while (fast != NULL)
    {
        last = fast;
        fast = fast->next;
        len++;
    }
    
    // Check if k is greater than the list size
    k = k % len;
    
    if (k == 0)
    {
        return head;
    }
    
    fast = head;
    ListNode* slow = NULL;
    
    int count = len - k;
    // Get pointers to the nodes where we have to break and switch the list
    while (count != 0)
    {
        slow = fast;
        fast = fast->next;
        count--;
    }
    
    // Update the pointers
    last->next = head;
    slow->next = NULL;
    head = fast;
    
    return head;
}