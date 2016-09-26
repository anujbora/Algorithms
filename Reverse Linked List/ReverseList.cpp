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

ListNode* ReverseListRecursively(ListNode* head) 
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode* node = ReverseListRecursively(head->next);

    head->next->next = head;
    head->next = NULL;

    return node;
}

ListNode* ReverseListIteratively(ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode* temp;
    ListNode* slow = NULL;
    ListNode* fast = head;

    while (fast != NULL)
    {
        temp = fast->next;
        fast->next = slow;
        slow = fast;
        fast = temp;
    }

    head = slow;

    return head;
}