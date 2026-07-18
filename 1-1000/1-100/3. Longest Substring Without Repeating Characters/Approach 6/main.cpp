// Jump the left boundary using each character's last seen index.
// Time: O(n) expected, Space: O(min(n, 256)).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<unsigned char, int> lastSeen;
        int left = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            auto it = lastSeen.find(c);
            if (it != lastSeen.end()) {
                left = max(left, it->second + 1);
            }
            lastSeen[c] = right;
            best = max(best, right - left + 1);
        }

        return best;
    }
};
