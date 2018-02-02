/**
 * File: max-consecutive-ones.cpp * https://leetcode.com/problems/max%20consecutive%20ones/
 * By zuimrs
 * Runtime:  46 ms
 * Language: cpp
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0,n = 0 ; 
        for(int i = 0 ; i< nums.size();++i)
        {
            if(nums[i]== 0)
            {
                n=0 ;
                continue;
            }
            
            n++;            
            max = max > n ? max : n;             
          
        }
        return max;
    }
};