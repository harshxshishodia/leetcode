// Start at every position and extend until the first duplicate.
// Time: O(n^2) expected, Space: O(min(n, 256)).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best = 0;

        for (int left = 0; left < static_cast<int>(s.size()); ++left) {
            unordered_set<unsigned char> seen;
            for (int right = left; right < static_cast<int>(s.size()); ++right) {
                unsigned char c = static_cast<unsigned char>(s[right]);
                if (!seen.insert(c).second) break;
                best = max(best, right - left + 1);
            }
        }

        return best;
    }
};
