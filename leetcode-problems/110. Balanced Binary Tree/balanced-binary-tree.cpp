/**
 * File: balanced-binary-tree.cpp * https://leetcode.com/problems/balanced%20binary%20tree/
 * By zuimrs
 * Runtime:  13 ms
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int d = height(root->left) - height(root->right);
        return (d >= -1 && d <= 1)&&isBalanced(root->left) && isBalanced(root->right) ;
    }
    int height(TreeNode * root){
        if(!root) return 0;
        return max(height(root->left),height(root->right)) + 1;
    }
};