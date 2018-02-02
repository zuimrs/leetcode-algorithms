/**
 * File: valid-palindrome.cpp * https://leetcode.com/problems/valid%20palindrome/
 * By zuimrs
 * Runtime:  15 ms
 * Language: cpp
 */

class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> stk;
        for(int i =  0; i<s.size(); ++i)
        {
            if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= '0' && s[i] <= '9'))
                stk.push(s[i]);
            else if(s[i] >= 'A' && s[i] <= 'Z')
                stk.push(s[i] - 'A' + 'a');
        }
        for(int i  = 0 ;  i < s.size() ; ++i)
        {
            if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= '0' && s[i] <= '9'))
            {
                if(s[i] != stk.top())
                    return false;
                stk.pop();
                
            }
            else if(s[i] >= 'A' && s[i] <= 'Z')
            {
                if(s[i] - 'A' + 'a' != stk.top())
                    return false;
                stk.pop();
            }

        }
        return true;
    }
};