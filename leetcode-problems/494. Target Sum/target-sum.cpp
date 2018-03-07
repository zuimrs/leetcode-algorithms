/**
 * File: target-sum.cpp * https://leetcode.com/problems/target%20sum/
 * By zuimrs
 * Runtime:  871 ms
 * Language: cpp
 */

class Solution {
public:
    int count = 0 ;
    int findTargetSumWays(vector<int>& nums, int S) {
        find(nums,0,S);
        return count;
    }
    void find(vector<int> & nums,int index,int S)
    {
        if(index >= nums.size())
        {
            if(S == 0)  count++;
            return;
        }
        find(nums,index+1,S + nums[index]);
        find(nums,index+1,S - nums[index]);
    }
};