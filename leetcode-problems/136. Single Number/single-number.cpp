/**
 * File: single-number.cpp * https://leetcode.com/problems/single%20number/
 * By zuimrs
 * Runtime:  15 ms
 * Language: cpp
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1 ; i < nums.size();++i)
        {
            res = res ^ nums[i];
        }
        return res;
    }
};