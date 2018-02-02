/**
 * File: distribute-candies.cpp * https://leetcode.com/problems/distribute%20candies/
 * By zuimrs
 * Runtime:  309 ms
 * Language: cpp
 */

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s(candies.begin(),candies.end());
        return s.size() > candies.size()/2 ? candies.size()/2 : s.size();
    }
};