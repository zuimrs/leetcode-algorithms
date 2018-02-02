/**
 * File: nim-game.cpp * https://leetcode.com/problems/nim%20game/
 * By zuimrs
 * Runtime:  0 ms
 * Language: cpp
 */

class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0) return false;
        return true;
    }
};