/**
 * File: add-strings.cpp * https://leetcode.com/problems/add%20strings/
 * By zuimrs
 * Runtime:  10 ms
 * Language: cpp
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int shift = 0;
        for(int i = num1.size() -1,j = num2.size() - 1; i >=0 || j >= 0 ; --i,--j)
        {
            int a = i >= 0 ? num1[i] - '0' : 0 ;
            int b = j >= 0 ? num2[j] - '0' : 0 ;
            int sum = a + b + shift;
            shift = sum / 10;
            result.insert(result.begin(),(sum%10)+'0');            
        }
        if(shift)
            result.insert(result.begin(),shift+'0');
        return result;
    }
};