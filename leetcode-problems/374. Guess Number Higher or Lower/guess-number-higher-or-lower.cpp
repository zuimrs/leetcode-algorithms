/**
 * File: guess-number-higher-or-lower.cpp * https://leetcode.com/problems/guess%20number%20higher%20or%20lower/
 * By zuimrs
 * Runtime:  0 ms
 * Language: cpp
 */

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int maxNumber = n, minNumber = 1;
        while (true) {
            int meanNumber = (maxNumber - minNumber) / 2 + minNumber;
            int res = guess(meanNumber);
            if (res == 0) { 
                return meanNumber;
            } else if (res == 1) {
                minNumber = meanNumber + 1;
            } else {
                maxNumber = meanNumber - 1;
            }
        }
    }
};