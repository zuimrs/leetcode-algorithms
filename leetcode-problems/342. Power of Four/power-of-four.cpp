/**
 * File: power-of-four.cpp * https://leetcode.com/problems/power%20of%20four/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 1)
            return false;
        while(num > 1)
        {
            if((num>>2)<<2 != num)
                return false;
            num >>= 2;
        }
        return true;
        

    }
};