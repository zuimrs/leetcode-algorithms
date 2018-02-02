/**
 * File: arranging-coins.cpp * https://leetcode.com/problems/arranging%20coins/
 * By zuimrs
 * Runtime:  32 ms
 * Language: cpp
 */

class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0;
        while(n > i)
        {
            i++;
            n-=i;

        }
        return i;
    }
};