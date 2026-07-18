// Quadratic expansion with a direct-addressed byte table.
// Time: O(n^2), Space: O(1) because the alphabet has 256 byte values.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best = 0;

        for (int left = 0; left < static_cast<int>(s.size()); ++left) {
            array<bool, 256> seen{};
            for (int right = left; right < static_cast<int>(s.size()); ++right) {
                unsigned char c = static_cast<unsigned char>(s[right]);
                if (seen[c]) break;
                seen[c] = true;
                best = max(best, right - left + 1);
            }
        }

        return best;
    }
};
