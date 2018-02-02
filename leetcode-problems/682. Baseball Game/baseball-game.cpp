/**
 * File: baseball-game.cpp * https://leetcode.com/problems/baseball%20game/
 * By zuimrs
 * Runtime:  6 ms
 * Language: cpp
 */

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> pool;
        int sum = 0;
        for(int i = 0 ; i < ops.size() ; i++)
        {
            if(ops[i] == "+")
            {
                int a = pool.top();
                pool.pop();
                int b = pool.top();
                pool.push(a);
                pool.push(a+b);
                sum += a+b;
            }else if(ops[i] == "C")
            {
                sum -= pool.top();
                pool.pop();
            }else if(ops[i] == "D")
            {
                sum += pool.top() * 2;
                pool.push(pool.top() * 2);
            }else
            {
                int n = atoi(ops[i].c_str());
                sum += n;
                pool.push(n);
            }
        }
        return sum;
    }
};