/**
 * File: best-time-to-buy-and-sell-stock.cpp * https://leetcode.com/problems/best%20time%20to%20buy%20and%20sell%20stock/
 * By zuimrs
 * Runtime:  9 ms
 * Language: cpp
 */

class Solution {
public:
int maxProfit(vector<int> &prices) {
    int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
}
};