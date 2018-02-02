/**
 * File: assign-cookies.cpp * https://leetcode.com/problems/assign%20cookies/
 * By zuimrs
 * Runtime:  46 ms
 * Language: cpp
 */

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.empty()||s.empty())
            return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0,j = 0;
        while(i < g.size() && j < s.size())
        {
            if(g[i] <= s[j])
            {
                i++,j++;
            }else
            {
                j++;
            }
        }
        return i;
    }
};