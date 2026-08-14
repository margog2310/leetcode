/*
    Given an encoded string s, write a function to return its decoded string.

    The encoding rule is k[encoded_string], where the encoded_string inside the 
    square brackets is repeated exactly k times. k is always a positive integer, 
    and the brackets can be nested.

    You can assume the input is always well-formed: there are no extra spaces, 
    every square bracket is properly matched, and digits only ever appear to 
    specify a repeat count k (so you won't see input like 3a or 2[4]).
*/

#include "stack.hpp"

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<int> nbrs;
        std::stack<std::string> str;
        std::string  decoded = "";
        int currentNbr = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[')
            {
                nbrs.push(currentNbr);
                str.push(decoded);
                currentNbr = 0;
                decoded = "";
            }
            else if (s[i] == ']')
            {
                int repeat = nbrs.top();
                nbrs.pop();
                std::string  prev = str.top();
                str.pop();
                std::string temp = "";
                for (int j = 0; j < repeat; j++)
                    temp += decoded;
                decoded = prev + temp;
            }
            else if (isdigit(s[i]))
                currentNbr = currentNbr * 10 + s[i] - '0';
            else
                decoded += s[i];
        }
        return decoded;
    }
};