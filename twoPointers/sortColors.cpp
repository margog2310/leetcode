/*
    Write a function to sort a given integer array nums in-place (and without 
    the built-in sort function), where the array contains n integers that are 
    either 0, 1, and 2 and represent the colors red, white, and blue. Arrange 
    the objects so that same-colored ones are adjacent, in the order of red, 
    white, and blue (0, 1, 2).
*/

#include "twoPointers.hpp"

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                std::swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
                mid++;
            else
            {
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};