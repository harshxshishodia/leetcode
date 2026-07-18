// Scan right-to-left and cap each unique window at the next duplicate.
// Time: O(n), Space: O(1).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = static_cast<int>(s.size());
        array<int, 256> nextSeen;
        nextSeen.fill(n);
        int right = n;
        int best = 0;

        for (int left = n - 1; left >= 0; --left) {
            unsigned char c = static_cast<unsigned char>(s[left]);
            right = min(right, nextSeen[c]);
            best = max(best, right - left);
            nextSeen[c] = left;
        }

        return best;
    }
};
