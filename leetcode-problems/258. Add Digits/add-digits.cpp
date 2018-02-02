/**
 * File: add-digits.cpp * https://leetcode.com/problems/add%20digits/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    int addDigits(int num) {
        int t;
        while(num/10)
        {
            t = 0;
            while(num)
            {
                t += num % 10;
                num /= 10;
            }
            num = t;
        }
        return num;
    }
};