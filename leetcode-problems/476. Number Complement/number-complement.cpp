/**
 * File: number-complement.cpp * https://leetcode.com/problems/number%20complement/
 * By zuimrs
 * Runtime:  6 ms
 * Language: cpp
 */

class Solution {
public:
    int findComplement(int num) {
        int a = 0,b=num;
        while(b)
        {
            b >>=1;
            a++;
        }
        return (1<<a)+(~num);
    }
};