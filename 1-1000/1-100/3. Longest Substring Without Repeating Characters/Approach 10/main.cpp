// Sliding window backed by a 256-bit membership table.
// Time: O(n), Space: O(1).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bitset<256> inWindow;
        int left = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            while (inWindow.test(c)) {
                inWindow.reset(static_cast<unsigned char>(s[left++]));
            }
            inWindow.set(c);
            best = max(best, right - left + 1);
        }

        return best;
    }
};
