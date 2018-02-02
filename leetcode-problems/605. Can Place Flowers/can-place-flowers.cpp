/**
 * File: can-place-flowers.cpp * https://leetcode.com/problems/can%20place%20flowers/
 * By zuimrs
 * Runtime:  19 ms
 * Language: cpp
 */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        for (int i = 0; i < bed.size(); i++) {
            if (!bed[i] && (i == 0 || !bed[i - 1]) && (i == bed.size() - 1 || !bed[i + 1])) {
                bed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};