/**
 * File: rotate-array.cpp * https://leetcode.com/problems/rotate%20array/
 * By zuimrs
 * Runtime:  33 ms
 * Language: cpp
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0||k==n)
            return;
        k = k % n;
        reverse(nums.begin(), nums.begin() + n - k) ;
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }

};