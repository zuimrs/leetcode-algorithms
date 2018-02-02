/**
 * File: factorial-trailing-zeroes.cpp * https://leetcode.com/problems/factorial%20trailing%20zeroes/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : trailingZeroes(n / 5) + n / 5;
    }
};