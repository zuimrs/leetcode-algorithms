/**
 * File: reverse-string.cpp * https://leetcode.com/problems/reverse%20string/
 * By zuimrs
 * Runtime:  9 ms
 * Language: cpp
 */

class Solution {
public:
    string reverseString(string s) {
        string res = s;
        int size = s.size()-1;
        for(int i = 0;i < s.size(); ++i)
        {
            res[i] = s[size-i];
        }
        return res;
    }
};