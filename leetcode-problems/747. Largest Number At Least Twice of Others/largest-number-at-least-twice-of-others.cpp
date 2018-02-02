/**
 * File: largest-number-at-least-twice-of-others.cpp * https://leetcode.com/problems/largest%20number%20at%20least%20twice%20of%20others/
 * By zuimrs
 * Runtime:  6 ms
 * Language: cpp
 */

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max,max_index;
        int second;
        max_index = 0;
        if(nums.size() <= 1)
            return max_index;
        max = nums[0];
        second = nums[1];
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            if( nums[i] > max ) 
            {
                second = max;
                max = nums[i];
                max_index = i;
            }else if(nums[i] < max && nums[i] > second)
            {
                second = nums[i];
            }
        }
        if(max < 2 * second)
            max_index = -1;
        return max_index;
    }
    
};