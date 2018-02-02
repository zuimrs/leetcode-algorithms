/**
 * File: move-zeroes.cpp * https://leetcode.com/problems/move%20zeroes/
 * By zuimrs
 * Runtime:  16 ms
 * Language: cpp
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int count = 0;
        for(int i = 0 ; i < nums.size();++i)
        {
            if(nums[i] == 0)
            {
                continue;
            }
            res[count++] = nums[i];
        }
        nums = res;
    }
};