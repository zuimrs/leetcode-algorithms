/**
 * File: maximum-product-of-three-numbers.cpp * https://leetcode.com/problems/maximum%20product%20of%20three%20numbers/
 * By zuimrs
 * Runtime:  69 ms
 * Language: cpp
 */

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int temp1 = nums[n-1]*nums[n-2]*nums[n-3];
        int temp2 = nums[0]*nums[1]*nums[n-1];
        return temp1>temp2?temp1:temp2;
    }
};