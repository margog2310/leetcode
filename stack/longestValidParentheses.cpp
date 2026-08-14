/*
    Given a string containing just the characters '(' and ')', find the 
    length of the longest valid (well-formed) parentheses substring. A 
    well-formed parentheses string is one that follows these rules:

    Open brackets must be closed by a matching pair in the correct order.
    For example, given the string "(()", the longest valid parentheses substring 
    is "()", which has a length of 2. Another example is the string ")()())", 
    where the longest valid parentheses substring is "()()", which has a length of 4.
*/

#include "stack.hpp"

class Solution {
public:
    int longest_valid_parentheses(std::string s) {
        std::stack<int> st;
        int longest = 0, start = 0;
        st.push(-1);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (!st.empty())
                    longest = std::max(longest, i - st.top());
                else
                    st.push(i);
            }
        }
        return longest;
    }
};