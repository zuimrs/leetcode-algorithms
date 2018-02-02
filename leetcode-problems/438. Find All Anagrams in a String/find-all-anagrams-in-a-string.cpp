/**
 * File: find-all-anagrams-in-a-string.cpp * https://leetcode.com/problems/find%20all%20anagrams%20in%20a%20string/
 * By zuimrs
 * Runtime:  279 ms
 * Language: cpp
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s == "" || p ==""|| p.size() > s.size())
            return res;
        int c = p.size();
        int s1=0,s2=1,s3=0,s4=1;
        for(int i = 0 ;  i < c ; ++i)
        {
            s1 += p[i];
            s2 *= p[i];
        }
        for(int i = 0 ; i < s.size()-c+1;++i)
        {
            s3 = 0,s4=1;
            for(int j = i; j < i + c ; ++j)
            {
                s3+=s[j];
                s4*=s[j];
            }
            if(s1 == s3 && s2 == s4)
                res.push_back(i);
        }
        return res;
    }
};