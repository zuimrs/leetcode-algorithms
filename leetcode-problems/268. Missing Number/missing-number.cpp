/**
 * File: missing-number.cpp * https://leetcode.com/problems/missing%20number/
 * By zuimrs
 * Runtime:  33 ms
 * Language: cpp
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
            res ^= (i + 1) ^ nums[i];
        return res;
    }
};