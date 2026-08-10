/*
    Given an input integer array nums, write a function to
    find all unique triplets [nums[i], nums[j], nums[k]] such
    that i, j, and k are distinct indices, and the sum of
    nums[i], nums[j], and nums[k] equals zero. Ensure that 
    the resulting list does not contain any duplicate triplets.
*/

#include "twoPointers.hpp"

class Solution {
public:
    std::vector<std::vector<int> > threeSum(std::vector<int> nums) {
        std::vector<std::vector<int> > result;

        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i)
        {
            // skipping duplicate values for left side
            if (i > 0 && nums[i] == nums[i - 1])
                continue ;

            int left = i + 1;
            int right = n - 1;
            while (right > left)
            {
                long long sum = (long long)nums[i] + nums[left] + nums[right];
                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (right > left && nums[left] == nums[left + 1])
                        left++;
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    left++; // pointers should be moved inside loop
                    right--;
                }
            }
        }
        return result;
    }
};