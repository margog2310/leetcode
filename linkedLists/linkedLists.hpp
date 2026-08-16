#ifndef LINKEDLISTS_HPP
#define LINKEDLISTS_HPP

#include <iostream>
#include <algorithm>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int newVal): val(newVal), next(nullptr) {};
    ListNode(ListNode* newNode): val(newNode->val), next(newNode->next) {};
} ;

#endif