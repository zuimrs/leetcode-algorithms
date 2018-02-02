/**
 * File: reshape-the-matrix.cpp * https://leetcode.com/problems/reshape%20the%20matrix/
 * By zuimrs
 * Runtime:  43 ms
 * Language: cpp
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rows = nums.size();
        int cols = nums[0].size();
        
        if (rows * cols != r * c)
            return nums;
        
        vector<vector<int>> result(r, vector<int>(c, 0));
        
        for (int i = 0; i < r * c; i++)
        {
            result[i / c][i % c] = nums[i / cols][i % cols];
        }
        
        return result;
    }
};