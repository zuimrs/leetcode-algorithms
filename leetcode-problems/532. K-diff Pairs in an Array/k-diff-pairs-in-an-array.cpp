/**
 * File: k-diff-pairs-in-an-array.cpp * https://leetcode.com/problems/k%20diff%20pairs%20in%20an%20array/
 * By zuimrs
 * Runtime:  32 ms
 * Language: cpp
 */

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int,int> map;
        for(int i = 0 ; i < nums.size(); ++i)
        {
            map[nums[i]] ++;
        }
        unordered_map<int,int>::iterator iter;
        int cnt = 0;
        for(iter = map.begin();iter!= map.end();++iter)
        {
            if((!k&&iter->second>1)||(k&&map.count(iter->first+k)))
                ++cnt;
        }
        return cnt;
    }
};