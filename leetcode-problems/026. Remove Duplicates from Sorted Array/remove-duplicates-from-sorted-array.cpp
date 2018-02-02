/**
 * File: remove-duplicates-from-sorted-array.cpp * https://leetcode.com/problems/remove%20duplicates%20from%20sorted%20array/
 * By zuimrs
 * Runtime:  52 ms
 * Language: cpp
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = 1,last = nums[0];
        for(int i =1 ; i < nums.size();++i)
        {
            if(last != nums[i]){
                res++;
                last = nums[i];
            }else
            {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return res;
    }
};