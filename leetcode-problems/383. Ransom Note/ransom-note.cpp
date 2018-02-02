/**
 * File: ransom-note.cpp * https://leetcode.com/problems/ransom%20note/
 * By zuimrs
 * Runtime:  23 ms
 * Language: cpp
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vec(26, 0);
        for (int i = 0; i < magazine.size(); ++i)
            ++vec[magazine[i] - 'a'];
        for (int j = 0; j < ransomNote.size(); ++j)
            if (--vec[ransomNote[j] - 'a'] < 0)
                return false;
        return true;        
    }
};