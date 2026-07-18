// Sliding window with four 64-bit integers as a 256-bit membership mask.
// Time: O(n), Space: O(1).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<unsigned long long, 4> mask{};
        int left = 0;
        int best = 0;

        auto contains = [&mask](unsigned char c) {
            return (mask[c >> 6] & (1ULL << (c & 63))) != 0;
        };
        auto insert = [&mask](unsigned char c) {
            mask[c >> 6] |= 1ULL << (c & 63);
        };
        auto erase = [&mask](unsigned char c) {
            mask[c >> 6] &= ~(1ULL << (c & 63));
        };

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            while (contains(c)) {
                erase(static_cast<unsigned char>(s[left++]));
            }
            insert(c);
            best = max(best, right - left + 1);
        }

        return best;
    }
};
