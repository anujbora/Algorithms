#include <iostream>
#include <algorithm>
using namespace std;

/*
 *  Time Complexity : O(n); where n is the number of nodes in the Linked List
 *  Space Complexity  : O(1)
 */

// Structure of a node of the Linked List
struct ListNode
{
    int data;
    struct ListNode* next;
    ListNode(int val) : data(val), next(NULL) {}
};

ListNode* addOne(ListNode* head)
{
    ListNode* dummy = new ListNode(0);

    if (head == NULL)
    {
        dummy->data++;
        return dummy;
    }

    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->data != 9)
        {
            slow = fast;
        }
    }

    if (fast->data == 9)
    {
        slow->data++;
        slow = slow->next;

        while(slow != NULL)
        {
            slow->data = 0;
            slow = slow->next;
        }
    }
    else
    {
        fast->data++;
    }

    if (dummy->data != 0)
    {
        return dummy;
    }
    else
    {
        return dummy->next;
    }
}