/*
    Given an integer array nums, write a function to rearrange the array by 
    moving all zeros to the end while keeping the order of non-zero elements 
    unchanged. Perform this operation in-place without creating a copy of the 
    array.
*/

#include "twoPointers.hpp"

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int nextNonZero = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                std::swap(nums[nextNonZero], nums[i]);
                nextNonZero++;
            }
        }
    }
};