/**
 * File: find-the-difference.cpp * https://leetcode.com/problems/find%20the%20difference/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    char findTheDifference(string s, string t) {
        int s1,s2;
        s1 = accumulate(s.begin(),s.end(),0);
        s2 = accumulate(t.begin(),t.end(),0);
        return char(s2-s1);
    }
};