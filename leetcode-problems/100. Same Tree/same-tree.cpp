/**
 * File: same-tree.cpp * https://leetcode.com/problems/same%20tree/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((!p)&&(!q)) return true;
        else if((!p)||(!q)) return false;
        else if(p->val != q->val) return false;
        else
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};