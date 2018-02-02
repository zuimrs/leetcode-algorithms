/**
 * File: length-of-last-word.cpp * https://leetcode.com/problems/length%20of%20last%20word/
 * By zuimrs
 * Runtime:  6 ms
 * Language: cpp
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int i,end = s.size()-1;
        bool hasWord = false;
        for(i= s.size()-1; i >=0;--i)
        {
            if(s[i] != ' '&&!hasWord)
            {
                hasWord=true;
                end = i;
            }
            else if(s[i] ==' ' && !hasWord)
                continue;
            else if(s[i]==' ' && hasWord)
                break;
        }
        if(!hasWord) return 0;
        return end-i;
    }
};