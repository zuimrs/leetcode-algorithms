/**
 * File: contains-duplicate.cpp * https://leetcode.com/problems/contains%20duplicate/
 * By zuimrs
 * Runtime:  36 ms
 * Language: cpp
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();      
    }
};