/**
 * File: merge-sorted-array.cpp * https://leetcode.com/problems/merge%20sorted%20array/
 * By zuimrs
 * Runtime:  9 ms
 * Language: cpp
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }   
    }
};