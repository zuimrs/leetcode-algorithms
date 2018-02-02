/**
 * File: fizz-buzz.cpp * https://leetcode.com/problems/fizz%20buzz/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n,"");
        for(int i = 0; i < res.size();++i)
        {
            if((i+1)%15==0)
            {
                res[i] =  "FizzBuzz";
                continue;
            }
            if((i+1)%3==0)
            {
                res[i] = "Fizz";
                continue;
            }
            if((i+1)%5==0)
            {
                res[i] = "Buzz";
                continue;               
            }
            res[i] = to_string(i+1);
        }
        return res;
    }
};