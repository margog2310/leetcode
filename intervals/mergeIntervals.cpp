/*
    Write a function to consolidate overlapping intervals within a given 
    array intervals, where each interval intervals[i] consists of a start 
    time starti and an end time endi.

    Two intervals are considered overlapping if they share any common time, 
    including if one ends exactly when another begins (e.g., [1,4] and [4,5] 
    overlap and should be merged into [1,5]).

    The function should return an array of the merged intervals so that no 
    two intervals overlap and all the intervals collectively cover all the 
    time ranges in the original input.
*/

#include "intervals.hpp"

class Solution {
public:
    std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>> intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size();i++)
        {
            if (intervals[i][0] <= intervals[i - 1][1])
            {
                intervals[i - 1][0] = std::min(intervals[i - 1][0], intervals[i][0]);
                intervals[i - 1][1] = std::max(intervals[i - 1][1], intervals[i][1]);
                intervals.erase(intervals.begin() + i--);
            }
        }
        return intervals;
    }
};