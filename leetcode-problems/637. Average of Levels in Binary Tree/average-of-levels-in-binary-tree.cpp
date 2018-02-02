/**
 * File: average-of-levels-in-binary-tree.cpp * https://leetcode.com/problems/average%20of%20levels%20in%20binary%20tree/
 * By zuimrs
 * Runtime:  16 ms
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        double count = 0,sum = 0;
        while(!q.empty())
        {
            TreeNode * p = q.front();
            q.pop();
            if(!p)
            {
                res.push_back(sum/count);
                count = 0,sum = 0;
                if(!q.empty()) q.push(NULL);
            }else{
                sum += p->val;
                count++;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return res;
        
        
    }
};