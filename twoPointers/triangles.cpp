/*
    Write a function to count the number of triplets in an integer array nums 
    that could form the sides of a triangle.

    For three sides to form a valid triangle, all three of these conditions must
    hold: (a + b > c), (a + c > b), and (b + c > a), where (a), (b), and (c) are
    the side lengths. In other words, the sum of every possible pair must exceed
    the third side.
*/

#include "twoPointers.hpp"

class Solution {
public:
    int triangleNumber(std::vector<int> nums) {
        int triangles = 0;

        std::sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i > 1; i--)
        {
            int left = 0;
            int right = i - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    triangles += right - left;
                    right--;
                }
                else
                    left++;
            }
        }
        return triangles;
    }
};