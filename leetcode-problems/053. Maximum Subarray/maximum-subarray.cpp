/**
 * File: maximum-subarray.cpp * https://leetcode.com/problems/maximum%20subarray/
 * By zuimrs
 * Runtime:  12 ms
 * Language: cpp
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0],i,j,sum=0;
        for(i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            res = max(res,sum);
            sum = max(sum,0);
        }
        return res;
    }
};