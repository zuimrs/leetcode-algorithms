/**
 * File: merge-two-sorted-lists.cpp * https://leetcode.com/problems/merge%20two%20sorted%20lists/
 * By zuimrs
 * Runtime:  12 ms
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode res(0),*p = &res;
        int v1,v2;
        while(l1||l2)
        {
            if(l1&&l2)
            {
                if(l1->val < l2->val)
                {
                    p->next = l1;                    
                    l1 = l1->next;
                }
                else{
                    p->next = l2;
                    l2 = l2->next;
                }
            }
            else if(l1)
            {
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        return res.next;
    }
};