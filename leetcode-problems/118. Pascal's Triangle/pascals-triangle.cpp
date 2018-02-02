/**
 * File: pascals-triangle.cpp * https://leetcode.com/problems/pascals%20triangle/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        for(int i = 0; i < numRows; ++i )
        {
            vector<int> s(i+1,1);
            for(int j = 1 ; j < i ;++j)
            {
                s[j] = res[i-1][j-1]+  res[i-1][j];     
            }
            res.push_back(s);
        }
        return res;
    }
};