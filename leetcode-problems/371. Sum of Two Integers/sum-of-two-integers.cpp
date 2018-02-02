/**
 * File: sum-of-two-integers.cpp * https://leetcode.com/problems/sum%20of%20two%20integers/
 * By zuimrs
 * Runtime:  0 ms
 * Language: cpp
 */

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        
        while (b != 0)
        {
            sum = a ^ b;//calculate sum of a and b without thinking the carry 
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }
        
        return sum;
    }
};