/*
    Given an integer array temps representing daily temperatures, write a 
    function to calculate the number of days one has to wait for a warmer 
    temperature after each given day. The function should return an array 
    answer where answer[i] represents the wait time for a warmer day after 
    the ith day. If no warmer day is expected in the future, set answer[i] to 0.
*/

#include "stack.hpp"

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int> temps) {
        std::stack<int>  st;
        std::vector<int> result(temps.size(), 0);
        for (int i = 0; i < temps.size(); i++)
        {
            while (!st.empty() && temps[i] > temps[st.top()])
            {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};