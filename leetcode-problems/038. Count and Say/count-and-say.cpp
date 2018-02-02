/**
 * File: count-and-say.cpp * https://leetcode.com/problems/count%20and%20say/
 * By zuimrs
 * Runtime:  3 ms
 * Language: cpp
 */

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if(n<2) return s;
        for(int i =2;i<=n;++i)
        {
            string tmp =s;
            s = "";
            for(int j = 0; j < tmp.size();++j)
            {
                char cur = tmp[j];
                int count = 0;
                while(j<tmp.size()&& cur == tmp[j])
                {
                    ++j;
                    ++count;
                }
                --j;
                int a = count *10 + cur-'0';
                s += to_string(a);
            }
            s += "\0";
        }
        return s;
    }
};