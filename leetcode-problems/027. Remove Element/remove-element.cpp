/**
 * File: remove-element.cpp * https://leetcode.com/problems/remove%20element/
 * By zuimrs
 * Runtime:  6 ms
 * Language: cpp
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size()-1;
        for(int i = 0 ; i <= n ; ++i)
        {
            if(nums[i] == val)
            {
                int tmp = nums[i];
                nums[i] = nums[n];
                nums[n] = tmp;
                n--;
                i--;
            }
        }
        return n+1;
    }
};