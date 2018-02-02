/**
 * File: min-cost-climbing-stairs.cpp * https://leetcode.com/problems/min%20cost%20climbing%20stairs/
 * By zuimrs
 * Runtime:  9 ms
 * Language: cpp
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i = 0 ;
        int sumA = 0,sumB = 0;
        while(i < cost.size())
        {
            
            if(i % 2 == 0)
            {
                sumA += cost[i];
                sumB = sumB < sumA ? sumB : sumA;
            }else
            {
                sumB += cost[i];
                sumA = sumA < sumB ? sumA : sumB;
            }
            i++;           
        }
        return sumA < sumB ? sumA : sumB;
    }
};