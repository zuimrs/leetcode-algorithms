/**
 * File: valid-parentheses.cpp * https://leetcode.com/problems/valid%20parentheses/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        char c;
        for(int i =0 ; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] =='[' || s[i] == '{')
                s1.push(s[i]);
            else
            {
                if(s1.empty()) return false;
                c = s1.top();
                s1.pop();                
            }
            if(s[i]==')' && c != '(')
                return false;
            else if(s[i]==']' && c != '[')
                return false;
            else if (s[i]=='}' && c != '{')
                return false;
        }
        if(s1.empty())
            return true;
        return false;
    }
};