/**
 * File: perfect-number.cpp * https://leetcode.com/problems/perfect%20number/
 * By zuimrs
 * Runtime:  6 ms
 * Language: cpp
 */

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int n = num - 1 ,len = sqrt(num);
        for(int i = 2 ; i <= len; i++)
        {
            if(num % i == 0)
                n-=(i+num/i);
            if(n < 0)
                return false;
        }
        if(n == 0)
            return true;
        return false;
    }
};