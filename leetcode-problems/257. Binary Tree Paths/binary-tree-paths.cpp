/**
 * File: binary-tree-paths.cpp * https://leetcode.com/problems/binary%20tree%20paths/
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root) return result;
        help(result,root,to_string(root->val));
        return result;
    }
    void help(vector<string> & result,TreeNode * root,string s)
    {
        if(!root->left && !root->right) {
            result.push_back(s);
            return;
        }
        if(root->left)
           help(result,root->left, s + "->" + to_string(root->left->val));
        if(root->right)
           help(result,root->right, s + "->" + to_string(root->right->val));
    }
};