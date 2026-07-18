// Sliding window with character frequencies in a hash table.
// Time: O(n) expected, Space: O(min(n, 256)).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<unsigned char, int> frequency;
        int left = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            ++frequency[c];
            while (frequency[c] > 1) {
                --frequency[static_cast<unsigned char>(s[left++])];
            }
            best = max(best, right - left + 1);
        }

        return best;
    }
};
