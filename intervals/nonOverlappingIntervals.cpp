/*
    Write a function to return the minimum number of intervals that must 
    be removed from a given array intervals, where intervals[i] consists 
    of a starting point starti and an ending point endi, to ensure that 
    the remaining intervals do not overlap. Intervals that only touch at 
    their endpoints are not considered overlapping (e.g., [2,5] and [5,7] 
    do not overlap).
*/

#include "intervals.hpp"

class Solution {
public:
    int nonOverlappingIntervals(std::vector<std::vector<int>> intervals) {
        int n = 0;

        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, 
            const std::vector<int>& b){ return a[1] < b[1]; });
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[i - 1][1])
            {
                intervals.erase(intervals.begin() + i);
                n++;
                i--;
            }
        }
        return n;
    }
};