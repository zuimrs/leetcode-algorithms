/**
 * File: merge-two-binary-trees.cpp * https://leetcode.com/problems/merge%20two%20binary%20trees/
 * By zuimrs
 * Runtime:  52 ms
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        TreeNode * tmp = NULL;
        tmp = new TreeNode(t1->val+t2->val);
        tmp->left = mergeTrees(t1->left,t2->left);
        tmp->right = mergeTrees(t1->right,t2->right);

        return tmp;
    }
};