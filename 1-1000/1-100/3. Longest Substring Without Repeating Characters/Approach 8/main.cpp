// Last-seen boundary jumps with a fixed byte array.
// Time: O(n), Space: O(1).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 256> lastSeen;
        lastSeen.fill(-1);
        int left = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            left = max(left, lastSeen[c] + 1);
            lastSeen[c] = right;
            best = max(best, right - left + 1);
        }

        return best;
    }
};
