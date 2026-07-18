// Store one-based next-valid window starts for direct boundary updates.
// Time: O(n), Space: O(1).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 256> nextStart{};
        int left = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            left = max(left, nextStart[c]);
            best = max(best, right - left + 1);
            nextStart[c] = right + 1;
        }

        return best;
    }
};
