/**
 * File: construct-the-rectangle.cpp * https://leetcode.com/problems/construct%20the%20rectangle/
 * By zuimrs
 * Runtime:  109 ms
 * Language: cpp
 */

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res;
        int n = sqrt(area - 1);
        for(int i = n + 1; i <= area; ++i)
        {
            if(area % i ==0)
            {
                res.push_back(i);
                res.push_back(area/i);
                break;
            }
        }
        return res;
    }
};