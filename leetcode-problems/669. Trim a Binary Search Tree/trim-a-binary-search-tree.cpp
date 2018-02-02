/**
 * File: trim-a-binary-search-tree.cpp * https://leetcode.com/problems/trim%20a%20binary%20search%20tree/
 * By zuimrs
 * Runtime:  19 ms
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)
        {
            return root;
        }
        root->left = trimBST(root->left,L,R);
        root->right = trimBST(root->right,L,R);

        if(root->val >= L && root->val <=R)
        {
            return root;
        }else if(root->val < L)
        {
            return trimBST(root->right,L,R);
        }else{
            return trimBST(root->left,L,R);
        }
    }
};