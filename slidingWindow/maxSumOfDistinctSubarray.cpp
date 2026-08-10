/*
    Given an integer array nums and an integer k, write a function to 
    identify the highest possible sum of a subarray within nums, where 
    the subarray meets the following criteria: its length is k, and all 
    of its elements are unique. If no such subarray exists, return 0.
*/

#include "slidingWindow.hpp"

class Solution {
public:
    long long maxSum(std::vector<int> nums, int k) {
        long long sumMax = LLONG_MIN;
        long long windowSum = 0;
        int start = 0;
        std::unordered_map<int, int> hashMap;

        for (int end = 0; end < nums.size(); end++)
        {
            windowSum += nums[end];
            hashMap[nums[end]]++;
            if (end - start + 1 == k)
            {
                if (hashMap.size() == k)
                    sumMax = std::max(sumMax, windowSum);
                windowSum -= nums[start];
                if (hashMap[nums[start]] - 1 == 0)
                    hashMap.erase(nums[start]);
                start++;
            }
        }
        return sumMax == LLONG_MIN ? 0 : sumMax;
    }
};