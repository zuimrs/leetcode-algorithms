/**
 * File: sum-of-square-numbers.cpp * https://leetcode.com/problems/sum%20of%20square%20numbers/
 * By zuimrs
 * Runtime:  4 ms
 * Language: cpp
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        int start = 0 , end = sqrt(c);
        while(start <= end)
        {
            int sum = start * start + end * end;
            if( sum == c)
                return true;
            else if(sum > c)
                end --;
            else
                start++;
        }
        return false;
    }
};