/**
 * File: 1-bit-and-2-bit-characters.cpp * https://leetcode.com/problems/1%20bit%20and%202%20bit%20characters/
 * By zuimrs
 * Runtime:  6 ms
 * Language: cpp
 */

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0 ;
        for(i; i < bits.size() - 1 ; ++i)
        {
            if(bits[i] == 1)
                i++;
        }
        return i == bits.size() - 1;
    }
};