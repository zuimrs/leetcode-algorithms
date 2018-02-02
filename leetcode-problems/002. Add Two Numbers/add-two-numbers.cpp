/**
 * File: add-two-numbers.cpp * https://leetcode.com/problems/add%20two%20numbers/
 * By zuimrs
 * Runtime:  45 ms
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode res(0),* iter = &res;
        int last = 0;
        while(l1||l2||last)
        {
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + last;
            last = sum /10;
            iter->next = new ListNode(sum%10);
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
            iter = iter->next;
        }
        return res.next;
    }
};