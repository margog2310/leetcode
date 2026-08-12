/*
    Write a function to check if a person can attend all the meetings 
    scheduled without any time conflicts. Given an array intervals, 
    where each element [s1, e1] represents a meeting starting at time s1 
    and ending at time e1, determine if there are any overlapping meetings. 
    If there is no overlap between any meetings, return true; otherwise, 
    return false.

    Note that meetings ending and starting at the same time, such as (0,5) 
    and (5,10), do not conflict.
*/

#include "intervals.hpp"

class Solution {
public:
    bool canAttendMeetings(std::vector<std::vector<int>> intervals) {
        if (intervals.empty())
            return true;

        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        }
        return true;
    }
};