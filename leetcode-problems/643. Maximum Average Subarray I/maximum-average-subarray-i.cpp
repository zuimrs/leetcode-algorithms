/**
 * File: maximum-average-subarray-i.cpp * https://leetcode.com/problems/maximum%20average%20subarray%20i/
 * By zuimrs
 * Runtime:  189 ms
 * Language: cpp
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i =0 ; i < k; ++i)
        {
            sum+=nums[i];
        }
        int max = sum;
        for(int i = k ; i < nums.size() ; ++i)
        {
            sum += nums[i] - nums[i-k];
            max = max>sum? max: sum;        
        }
        return (double)max*1.0/k;
    }
};