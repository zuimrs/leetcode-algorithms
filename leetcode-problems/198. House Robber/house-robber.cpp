/**
 * File: house-robber.cpp * https://leetcode.com/problems/house%20robber/
 * By zuimrs
 * Runtime:  0 ms
 * Language: cpp
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0,b = 0;
        for(int i = 0 ; i < nums.size(); ++i)
        {
            if(i % 2 == 0 )
                a = max(a+nums[i],b);
            else
                b = max(a,b+nums[i]);
        }
        return max(a,b);
    }
};