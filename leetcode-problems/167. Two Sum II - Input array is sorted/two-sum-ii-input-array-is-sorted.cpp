/**
 * File: two-sum-ii-input-array-is-sorted.cpp * https://leetcode.com/problems/two%20sum%20ii%20input%20array%20is%20sorted/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int index1=0;
        int index2=numbers.size()-1;
        
        while(numbers[index1]+numbers[index2]!=target)
        {
            if(numbers[index1]+numbers[index2]<target)
            {
                index1++;
            }
            else if(numbers[index1]+numbers[index2]>target)
            {
                index2--;
            }    
        }
        ret.push_back(index1+1);
        ret.push_back(index2+1);
        return ret;
    }
};