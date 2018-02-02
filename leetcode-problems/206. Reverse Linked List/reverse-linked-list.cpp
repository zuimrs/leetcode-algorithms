/**
 * File: reverse-linked-list.cpp * https://leetcode.com/problems/reverse%20linked%20list/
 * By zuimrs
 * Runtime:  9 ms
 * Language: cpp
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) { 
        if(head&&head->next)
        {
            ListNode* node = reverseList(head -> next);
            head -> next -> next = head;
            head -> next = NULL;
            return node;     
        }
        return head;
    }
};