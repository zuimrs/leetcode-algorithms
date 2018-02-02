/**
 * File: palindrome-number.cpp * https://leetcode.com/problems/palindrome%20number/
 * By zuimrs
 * Runtime:  138 ms
 * Language: cpp
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x>0&&x%10==0)) return false;
        int sum = 0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x /= 10;
        }
        return sum==x||sum/10 ==x;
    }
};