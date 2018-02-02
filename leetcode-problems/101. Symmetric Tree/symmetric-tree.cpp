/**
 * File: symmetric-tree.cpp * https://leetcode.com/problems/symmetric%20tree/
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return equal(root->left,root->right);
    }
private:
    bool equal(TreeNode * p,TreeNode * q)
    {
        if(!p&&!q) return true;
        else if(!p||!q) return false;
        else if(p->val != q->val) return false;
        return equal(p->left,q->right)&&equal(p->right,q->left);
    }
};