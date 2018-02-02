/**
 * File: self-dividing-numbers.cpp * https://leetcode.com/problems/self%20dividing%20numbers/
 * By zuimrs
 * Runtime:  5 ms
 * Language: cpp
 */

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left ; i <= right ; ++i)
        {
            int tmp = i;
            while(tmp)
            {
                if(tmp % 10 == 0)
                    break;
                if(i % (tmp%10) != 0 )
                    break;
                tmp/=10;
            }
            if(tmp == 0 )
                result.push_back(i);
        }
        return result;
    }
};