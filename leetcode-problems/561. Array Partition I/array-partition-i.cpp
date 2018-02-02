/**
 * File: array-partition-i.cpp * https://leetcode.com/problems/array%20partition%20i/
 * By zuimrs
 * Runtime:  89 ms
 * Language: cpp
 */

#include <algotithm>
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i = 0;i < nums.size();i+=2)
        {
            sum+=nums[i];
        }
        return sum;
    }
};