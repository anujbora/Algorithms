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

ListNode* AddTwoNumbers(ListNode* head1, ListNode* head2) 
{
    int carry = 0;

    ListNode* traverse = NULL;
    ListNode* result = traverse;

    while (head1 || head2 || carry)
    {
        int sum = carry;

        if (head1)
        {
            sum = sum + head1->val;
            head1 = head1->next;
        }

        if (head2)
        {
            sum = sum + head2->val;
            head2 = head2->next;
        }

        ListNode* temp = new ListNode(sum % 10);
        carry = sum / 10;

        if (traverse == NULL)
        {
            result = temp;
        }
        else 
        {
            traverse->next = temp;
        }
        traverse = temp;
    }

    return result;
}