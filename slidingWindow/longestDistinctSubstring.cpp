/*
    Write a function to return the length of the longest substring in 
    a provided string s where all characters in the substring are distinct.
*/

#include "slidingWindow.hpp"

class Solution {
public:
    int longestSubstringWithoutRepeat(std::string s) {
        int maxLen = 0, start = 0;
        std::unordered_map<int, int> state;

        for (int end = 0; end < s.length(); end++)
        {
            if (state.find(s[end]) != state.end())
                start = std::max(start, state[s[end]] + 1);
            state[s[end]] = end;
            maxLen = std::max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};