/**
 * File: find-smallest-letter-greater-than-target.cpp * https://leetcode.com/problems/find%20smallest%20letter%20greater%20than%20target/
 * By zuimrs
 * Runtime:  19 ms
 * Language: cpp
 */

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        char min = 'z' + 1 , min2 = 'z';
        for(int i = 0 ; i < letters.size(); ++i)
        {
            if(letters[i] > target)
            {
                min = min < letters[i] ? min : letters[i];
            }
            min2 = min2 < letters[i] ? min2 :letters[i];
        }
        if(min == 'z' +  1)
            return min2;
        return min;
    }
};