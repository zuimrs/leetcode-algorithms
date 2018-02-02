/**
 * File: add-binary.cpp * https://leetcode.com/problems/add%20binary/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c >>= 1;
        }
        
        return s;
    }
};