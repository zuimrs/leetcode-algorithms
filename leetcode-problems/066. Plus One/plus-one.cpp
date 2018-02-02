/**
 * File: plus-one.cpp * https://leetcode.com/problems/plus%20one/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty())
        {
            digits.push_back(1);
            return digits;
        }
        digits[digits.size()-1]++;
        for(int i = digits.size()-1; i >= 0 ; --i)
        {
            if(digits[i]>=10)
            {
                digits[i] -= 10;
                if(i-1>=0)
                    digits[i-1] +=1;
                else{
                    digits.insert(digits.begin(),1);
                }
            }
        }
        return digits;
    }
};