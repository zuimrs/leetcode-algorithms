/**
 * File: container-with-most-water.cpp * https://leetcode.com/problems/container%20with%20most%20water/
 * By zuimrs
 * Runtime:  23 ms
 * Language: cpp
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
    }
};