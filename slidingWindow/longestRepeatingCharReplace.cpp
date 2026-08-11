/*
    Write a function to find the length of the longest substring 
    containing the same letter in a given string s, after performing 
    at most k operations in which you can choose any character of 
    the string and change it to any other uppercase English letter.
*/

#include "slidingWindow.hpp"

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int maxLen = 0, maxFreq = 0, start = 0;
        std::unordered_map<int, int> state;

        for (int end = 0; end < s.length(); end++)
        {
            state[s[end]]++;
            maxFreq = std::max(maxFreq, state[s[end]]);
            while (k + maxFreq < end - start + 1)
                state[s[start++]]--;
            maxLen = std::max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};