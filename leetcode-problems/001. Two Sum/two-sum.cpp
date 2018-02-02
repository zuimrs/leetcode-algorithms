/**
 * File: two-sum.cpp * https://leetcode.com/problems/two%20sum/
 * By zuimrs
 * Runtime:  10 ms
 * Language: cpp
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mapping;
        vector<int> result;
        for(int i = 0 ; i < nums.size(); ++i)
        {
            mapping[nums[i]] = i;
        }
        for(int i = 0 ; i < nums.size(); ++i)
        {
            int searched = target - nums[i];
            if(mapping.find(searched) != mapping.end() && i!= mapping[searched])
            {
                result.push_back(i);
                result.push_back(mapping[searched]);
                break;
            }
        }
        return result;
    }
};