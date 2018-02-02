/**
 * File: best-time-to-buy-and-sell-stock-ii.cpp * https://leetcode.com/problems/best%20time%20to%20buy%20and%20sell%20stock%20ii/
 * By zuimrs
 * Runtime:  6 ms
 * Language: cpp
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        if(prices.size()<2) return 0;
        for(int i=1;i<prices.size();++i)
        {
            sum+=prices[i] - prices[i-1] > 0 ? (prices[i] - prices[i-1]) : 0;
        }
        return sum;
    }
};