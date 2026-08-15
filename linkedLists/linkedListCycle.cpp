/*
    Write a function that takes in a parameter head of type ListNode 
    that is a reference to the head of a linked list. The function 
    should return True if the linked list contains a cycle, and False 
    otherwise, without modifying the linked list in any way.
*/

#include "linkedLists.hpp"

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *fast = head;
        ListNode* slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};