/**
 * File: judge-route-circle.cpp * https://leetcode.com/problems/judge%20route%20circle/
 * By zuimrs
 * Runtime:  19 ms
 * Language: cpp
 */

class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0,v = 0;
        for(int i = 0 ; i < moves.size() ; ++i)
        {
            if(moves[i] == 'L')
                h++;
            else if(moves[i] == 'R')
                h--;
            else if(moves[i] == 'U')
                v++;
            else
                v--;
        }
        return !(v||h);
    }
};