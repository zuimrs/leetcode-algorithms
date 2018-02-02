/**
 * File: delete-node-in-a-linked-list.cpp * https://leetcode.com/problems/delete%20node%20in%20a%20linked%20list/
 * By zuimrs
 * Runtime:  13 ms
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
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};