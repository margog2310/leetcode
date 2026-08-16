/*
    Given a reference head of type ListNode that is the head node of 
    a singly linked list and an integer n, write a function that removes 
    the n-th node from the end of the list and returns the head of the modified list.

    Note: n is guaranteed to be between 1 and the length of the list. If 
    n is the length of the list, the head of the list should be removed.
*/

#include "linkedLists.hpp"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* slow = temp;
        ListNode* fast = temp;

        for(int i = 0; i < n; i++)
            fast = fast->next;
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return temp->next;
    }
};