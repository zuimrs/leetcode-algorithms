/**
 * File: maximum-depth-of-binary-tree.cpp * https://leetcode.com/problems/maximum%20depth%20of%20binary%20tree/
 * By zuimrs
 * Runtime:  6 ms
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};