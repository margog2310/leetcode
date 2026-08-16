/*
    Given a reference of type ListNode which is the head of a singly 
    linked list, write a function to determine if the linked list is 
    a palindrome.

    A linked list is a palindrome if the values of the nodes are the 
    same when read from left-to-right and right-to-left. An empty list 
    is considered a palindrome.
*/

#include "linkedLists.hpp"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        while (slow)
        {
            ListNode* next_ = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next_;
        }

        ListNode* first = head;
        ListNode* second = prev;
        while (second)
        {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};