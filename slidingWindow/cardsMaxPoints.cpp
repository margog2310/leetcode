/*
    Given an array of integers representing card values, write a function 
    to calculate the maximum score you can achieve by picking exactly k cards.

    You must pick cards in order from either end. You can take some cards from 
    the beginning, then switch to taking cards from the end, but you cannot skip 
    cards or pick from the middle.

    For example, with k = 3:

    - Take the first 3 cards: valid
    - Take the last 3 cards: valid
    - Take the first card, then the last 2 cards: valid
    - Take the first 2 cards, then the last card: valid
    - Take card at index 0, skip some, then take card at index 5: not valid (skipping cards)
    Constraints: 1 <= k <= cards.length
*/

#include "slidingWindow.hpp"

class Solution {
public:
    int maxScore(std::vector<int> cards, int k) {
        int scoreMax = INT_MIN;
        int start = 0;
        int windowSum = 0, windowSize = cards.size() - k;
        int total = accumulate(cards.begin(), cards.end(), 0);

        if (k == cards.size())
            return total;
        for (int end = 0; end < cards.size(); end++)
        {
            windowSum += cards[end];
            if (end - start + 1 == windowSize)
            {
                int othersSum = total - windowSum;
                scoreMax = std::max(scoreMax, othersSum);
                windowSum -= cards[start];
                start++;
            }
        }
        return scoreMax;
    }
};