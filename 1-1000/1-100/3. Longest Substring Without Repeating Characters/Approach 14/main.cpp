// Dynamic programming with a fixed array of last positions.
// Time: O(n), Space: O(1).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 256> lastSeen;
        lastSeen.fill(-1);
        int suffixLength = 0;
        int best = 0;

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            unsigned char c = static_cast<unsigned char>(s[i]);
            if (i - lastSeen[c] > suffixLength) {
                ++suffixLength;
            } else {
                suffixLength = i - lastSeen[c];
            }

            lastSeen[c] = i;
            best = max(best, suffixLength);
        }

        return best;
    }
};
