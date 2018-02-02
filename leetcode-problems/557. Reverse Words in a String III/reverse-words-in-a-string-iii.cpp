/**
 * File: reverse-words-in-a-string-iii.cpp * https://leetcode.com/problems/reverse%20words%20in%20a%20string%20iii/
 * By zuimrs
 * Runtime:  22 ms
 * Language: cpp
 */

class Solution {
public:
    string reverseWords(string s) {
        string::iterator last = s.begin();
        string::iterator iter;
        for( iter = s.begin();iter!= s.end();iter++)
        {
            if((*iter == ' ')||(iter == s.end()))
            {
                reverse(last,iter);
                last = iter+1;
            }
        }
        reverse(last,iter);
        last = iter+1;
        return s;
    }
};