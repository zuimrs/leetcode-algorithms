/**
 * File: climbing-stairs.cpp * https://leetcode.com/problems/climbing%20stairs/
 * By zuimrs
 * Runtime:  0 ms
 * Language: cpp
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        int a = 1, b = 1,c;
        while (--n)
        {
            c = a + b;
            a  =b;
            b = c;
        }
        return c;
    }
};