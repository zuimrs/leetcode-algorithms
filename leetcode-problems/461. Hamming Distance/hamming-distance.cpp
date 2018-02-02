/**
 * File: hamming-distance.cpp * https://leetcode.com/problems/hamming%20distance/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int c = x^y;
        int res = 0;
        while(c)
        {
            if(((c>>1)<<1)!=c)
                ++res;
            c>>=1;
        }
        return res;
    }
};