/*
    Given an array of integers nums and an integer k, find the maximum 
    sum of any contiguous subarray of size k.
*/

#include "slidingWindow.hpp"

class Solution {
public:
    int maxSum(std::vector<int> nums, int k) {
        int maxSum = INT_MIN;
        int windowSum = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); end++)
        {
            windowSum += nums[end];
            if (end - start + 1 == k)
            {
                maxSum = std::max(maxSum, windowSum);
                windowSum -= nums[start];
                start++;
            }
        }
        return maxSum;
    }
};