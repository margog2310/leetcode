/*
    Write a function to find the common free time for all employees from 
    a list called schedule. Each employee's schedule is represented by a 
    list of non-overlapping intervals sorted by start times. The function 
    should return a list of finite, non-zero length intervals where all 
    employees are free, also sorted in order.
*/

#include "intervals.hpp"

class Solution {
public:
    std::vector<std::vector<int>> employeeFreeTime(std::vector<std::vector<std::vector<int>>> schedule) {
        std::vector<std::vector<int>> free;
        for (auto& i : schedule)
            free.insert(free.end(), i.begin(), i.end());
        sort(free.begin(), free.end());
        for (int i = 1; i < free.size(); i++)
        {
            if (free[i][0] <= free[i - 1][1])
            {
                free[i - 1][0] = std::min(free[i - 1][0], free[i][0]);
                free[i - 1][1] = std::max(free[i - 1][1], free[i][1]);
                free.erase(free.begin() + i--);
            }
        }
        std::vector<std::vector<int>> freeTime;
        for (int i = 0; i < free.size() - 1; i++)
        {
            int start = free[i][1];
            int end = free[i + 1][0];
            freeTime.push_back({start, end});
 
        }
        return freeTime;
    }
};