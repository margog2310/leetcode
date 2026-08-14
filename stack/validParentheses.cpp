/*
    Given an input string s consisting solely of the characters '(', ')', 
    '{', '}', '[' and ']', determine whether s is a valid string. A string 
    is considered valid if every opening bracket is closed by a matching 
    type of bracket and in the correct order, and every closing bracket 
    has a corresponding opening bracket of the same type.
*/  

#include "stack.hpp"

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<int> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {   
                if (st.empty())
                    return false;
                int c = st.top();
                if ((c == '(' && s[i] != ')') || (c == '[' && s[i] != ']') || 
                    (c == '{' && s[i] != '}'))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};