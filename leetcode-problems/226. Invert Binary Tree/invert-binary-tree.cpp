/**
 * File: invert-binary-tree.cpp * https://leetcode.com/problems/invert%20binary%20tree/
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
    TreeNode* invertTree(TreeNode* root) {
        if(root)
        {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left,root->right);
        }
        return root;
    }
};