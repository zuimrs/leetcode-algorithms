/**
 * File: remove-linked-list-elements.cpp * https://leetcode.com/problems/remove%20linked%20list%20elements/
 * By zuimrs
 * Runtime:  29 ms
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * p = head;
        while(p)
        {
            while(p->next&&p->next->val == val)
                p->next = p->next->next;
            p = p->next;
        }
        if(head&&head->val == val)
            return head->next;
        return head;
    }
};