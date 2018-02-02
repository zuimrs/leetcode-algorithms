/**
 * File: power-of-three.cpp * https://leetcode.com/problems/power%20of%20three/
 * By zuimrs
 * Runtime:  49 ms
 * Language: cpp
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && fmod(log10(n)/log10(3), 1)==0;
    }
};