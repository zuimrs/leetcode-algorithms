/**
 * File: 3sum-closest.cpp * https://leetcode.com/problems/3sum%20closest/
 * By zuimrs
 * Runtime:  10 ms
 * Language: cpp
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int minV = INT_MAX,record;
        int len = nums.size();
        for(int i = 0 ; i < len; ++i )
        {
            int start = i + 1, end = len - 1;
            while(start < end)
            {
                int sum = nums[i]+ nums[start] + nums[end];
                if(sum == target)
                {
                    minV = 0;
                    record = sum;
                    break;
                }
                if(sum > target)
                {
                    if(minV > sum - target)
                    {
                        record = sum;
                        minV = sum -target;
                    }
                    end --;
                }else
                {
                    if(minV > target - sum)
                    {
                        record = sum;
                        minV = target - sum;
                    }
                    start ++;
                }
            }
            if(record == target) break;
            while(i < len - 1 && nums[i] == nums[i + 1]) ++i;
        }
        return record;
    }
};