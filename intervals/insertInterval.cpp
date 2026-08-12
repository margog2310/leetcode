/*
    Given a list of intervals intervals and an interval newInterval, 
    write a function to insert newInterval into a list of existing, 
    non-overlapping, and sorted intervals based on their starting points. 
    The function should ensure that after the new interval is added, the 
    list remains sorted without any overlapping intervals, merging them if needed.

    Two intervals are considered overlapping if they share any common time, 
    including if one ends exactly when another begins (e.g., [1,4] and [4,7] 
    overlap and should be merged into [1,7]).
*/

#include "intervals.hpp"

class Solution {
public:
    std::vector<std::vector<int>> insertIntervals(std::vector<std::vector<int>> intervals, 
            std::vector<int> newInterval) {
        std::vector<std::vector<int>> merged;
        int i = 0;

        while (i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            merged.push_back(intervals[i]);
            i++;
        }
        
        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = std::min(intervals[i][0], newInterval[0]);
            newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            i++;
        }
        merged.push_back(newInterval);
        while (i < intervals.size())
        {
            merged.push_back(intervals[i]);
            i++;
        }

        return merged;
    }
};