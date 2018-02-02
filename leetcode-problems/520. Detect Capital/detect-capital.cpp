/**
 * File: detect-capital.cpp * https://leetcode.com/problems/detect%20capital/
 * By zuimrs
 * Runtime:  12 ms
 * Language: cpp
 */

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()<2) return true;
        if(word[0] >= 'A' && word[0] <= 'Z')
        {
            if(word[1] >= 'A' && word[1] <= 'Z')
            {
                for(int i = 2 ; i < word.size();++i)
                {
                    if(!(word[i] >= 'A' && word[i] <= 'Z'))
                        return false;
                }
                return true;
            }else{
                for(int i = 2 ; i < word.size();++i)
                {
                    if(word[i] >= 'A' && word[i] <= 'Z')
                        return false;
                }
                return true;
            }
        }else{
                for(int i = 1 ; i < word.size();++i)
                {
                    if(word[i] >= 'A' && word[i] <= 'Z')
                        return false;
                }
                return true;            
        }
        
    }
};