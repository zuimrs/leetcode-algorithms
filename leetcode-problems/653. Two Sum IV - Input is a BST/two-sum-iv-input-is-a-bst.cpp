/**
 * File: two-sum-iv-input-is-a-bst.cpp * https://leetcode.com/problems/two%20sum%20iv%20input%20is%20a%20bst/
 * By zuimrs
 * Runtime:  50 ms
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
    map<int,int> mapping;
    bool findTarget(TreeNode* root, int k) {
        preorder(root);
        for(map<int,int>::iterator iter = mapping.begin(); iter != mapping.end(); ++iter)
        {
            int target = k - iter->first;
            if(mapping.find(target) != mapping.end() && mapping.find(target) != iter)
                return true;
        }
        return false;
    }
    void preorder(TreeNode * root)
    {
        if(root){
            preorder(root->left);
            mapping[root->val] = 1;
            preorder(root->right);
        }
    }
};