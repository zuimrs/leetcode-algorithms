/**
 * File: reverse-integer.cpp * https://leetcode.com/problems/reverse%20integer/
 * By zuimrs
 * Runtime:  18 ms
 * Language: cpp
 */

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        if(x>0){
            while(x/10)
            {
                res = 10*(res+x%10);
                x = x/10;
            }
        }else
        {
            while(x/10)
            {
                res = 10*(res+x%10);
                x = x/10;
            }
        }
        res += x;
        if(res > INT_MAX || res < INT_MIN)
            return 0;
        return (int)res;
    }
};