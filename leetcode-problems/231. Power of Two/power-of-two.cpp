/**
 * File: power-of-two.cpp * https://leetcode.com/problems/power%20of%20two/
 * By zuimrs
 * Runtime:  6 ms
 * Language: cpp
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int i = 1;
        while(n>>i)
        {
            if((n>>i)<<i != n)
            {
                return false;
            }
            i++;
        }
        return true;
    }
};