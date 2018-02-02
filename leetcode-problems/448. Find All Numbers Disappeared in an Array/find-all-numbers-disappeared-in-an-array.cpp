/**
 * File: find-all-numbers-disappeared-in-an-array.cpp * https://leetcode.com/problems/find%20all%20numbers%20disappeared%20in%20an%20array/
 * By zuimrs
 * Runtime:  129 ms
 * Language: cpp
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> array(nums.size(),false);
        for(int i = 0 ; i < nums.size();++i)
        {
            array[nums[i]-1] = true;
        }
        vector<int> res;
        for(int i = 0 ; i < array.size();++i)
        {
            if(array[i] == false)
                res.push_back(i+1);
        }
        return res;
    }
};