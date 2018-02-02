/**
 * File: valid-perfect-square.cpp * https://leetcode.com/problems/valid%20perfect%20square/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
         int i = 1;
         while (num > 0) {
             num -= i;
             i += 2;
         }
         return num == 0;
    }
};