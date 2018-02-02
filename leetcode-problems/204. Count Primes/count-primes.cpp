/**
 * File: count-primes.cpp * https://leetcode.com/problems/count%20primes/
 * By zuimrs
 * Runtime:  59 ms
 * Language: cpp
 */

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        int count = 1;
        vector<bool>array(n,true);
        for(int i = 3; i < array.size(); i+=2)
        {
            if(array[i])
            {
                int n = 2;
                while(i*n<array.size())
                {
                    array[i*n]  =false;
                    n++;
                }
            }
        }
        
        for(int i = 3 ; i < array.size();i+=2)
        {
            if(array[i])
                count++;
        }
        return count;
    }
    
};