#include <iostream>
#include <algorithm>
using namespace std;

/**
 *  Time Complexity = O(n); where n is the number of elements in the linked list
 *  Space Complexity = O(1)
 */

struct ListNode
{
    int data;
    struct ListNode* next;
};

ListNode* ReorderList(ListNode* head) 
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    // Step 1 : Locate the middle node of the linked list
    ListNode* head1 = head;
    ListNode* head2 = head;
    while(head2->next && head2->next->next)
    {
        head1 = head1->next;
        head2 = head2->next->next;
    }
    if(head2->next)
    {
        head1 = head1->next;
    }

    // Step 2 : Split the linked list into two halves
    head2 = head1->next;
    head1->next = NULL;
    head1 = head;

    // Step 3 : Reverse the second half of the linked list
    ListNode* temp;
    ListNode* slow = NULL;
    ListNode* fast = head2;
    while(fast)
    {
        temp = fast->next;
        fast->next = slow;
        slow = fast;
        fast = temp;
    }
    head2 = slow;

    // Step 4 : Interleave the two linked lists
    ListNode* s = head1;
    head1 = head1->next;

    while(head1 && head2)
    {
        s->next = head2;
        head2 = head2->next;
        s = s->next;
      
        s->next = head1;
        s = s->next;
        head1 = head1->next;
    }
    if(head1)
    {
        head1->next=head1;
    }
    if(head2)
    {
        s->next=head2;
    }

    return head;
}