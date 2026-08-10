/*
    Given an array heights where each element represents 
    the height of a vertical line, pick two lines to form 
    a container. Return the maximum area (amount of water) 
    the container can hold.
    What is area? Width × height, where width is the distance
    between walls, and height is the shorter wall (water
    overflows at the shorter wall).
*/

#include "twoPointers.hpp"

class Solution {
public:
    int max_area(std::vector<int> heights) {
        int left = 0; 
        int right = heights.size() - 1;
        int best = 0;

        while (left < right)
        {
            int w = right - left;
            int h = std::min(heights[left], heights[right]);
            int currentArea = w * h;

            best = std::max(best, currentArea);

            if (heights[left] < heights[right])
                left++;
            else
                right--;
        }
        return best;
    }
};