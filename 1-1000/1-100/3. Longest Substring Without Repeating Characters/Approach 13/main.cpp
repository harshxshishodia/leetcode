// Dynamic programming: track the unique suffix length and hash last positions.
// Time: O(n) expected, Space: O(min(n, 256)).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<unsigned char, int> lastSeen;
        int suffixLength = 0;
        int best = 0;

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            unsigned char c = static_cast<unsigned char>(s[i]);
            auto it = lastSeen.find(c);

            if (it == lastSeen.end() || i - it->second > suffixLength) {
                ++suffixLength;
            } else {
                suffixLength = i - it->second;
            }

            lastSeen[c] = i;
            best = max(best, suffixLength);
        }

        return best;
    }
};
