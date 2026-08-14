/*
    Given an integer array heights representing the heights of 
    histogram bars, write a function to find the largest rectangular 
    area possible in a histogram, where each bar's width is 1.
*/

#include "stack.hpp"

class Solution {
public:
    int largestRectangleArea(std::vector<int> heights) {
        int largest = 0;
        std::stack<int>  st;
        int i = 0;
        while (i < heights.size())
        {
            if (st.empty() || heights[i] >= heights[st.top()])
                st.push(i++);
            else
            {
                int top = st.top();
                st.pop();
                int right = i - 1;
                int left = st.empty() ? -1 : st.top();
                int area = heights[top] * (right - left);
                largest = std::max(largest, area);
            }
        }
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            int area = heights[top] * w;
            largest = std::max(largest, area);
        }
        return largest;
    }
};