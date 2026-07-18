// Sliding window whose current characters are stored in a hash set.
// Time: O(n) expected, Space: O(min(n, 256)).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<unsigned char> window;
        int left = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            while (window.count(c)) {
                window.erase(static_cast<unsigned char>(s[left++]));
            }
            window.insert(c);
            best = max(best, right - left + 1);
        }

        return best;
    }
};
