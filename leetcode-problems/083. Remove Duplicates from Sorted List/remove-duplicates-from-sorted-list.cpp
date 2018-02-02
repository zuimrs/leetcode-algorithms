/**
 * File: remove-duplicates-from-sorted-list.cpp * https://leetcode.com/problems/remove%20duplicates%20from%20sorted%20list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * p = head;
        while(p)
        {
            while(p->next&&p->val == p->next->val)
            {
                p->next = p->next->next;
            }
            p = p->next;
        }
        return head;
    }
};