// Enumerate every substring and check whether all of its bytes are unique.
// Time: O(n^3), Space: O(min(n, 256)).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best = 0;

        for (int left = 0; left < static_cast<int>(s.size()); ++left) {
            for (int right = left + 1; right <= static_cast<int>(s.size()); ++right) {
                if (isUnique(s, left, right)) {
                    best = max(best, right - left);
                }
            }
        }

        return best;
    }

private:
    bool isUnique(const string& s, int left, int right) {
        unordered_set<unsigned char> seen;
        for (int i = left; i < right; ++i) {
            if (!seen.insert(static_cast<unsigned char>(s[i])).second) {
                return false;
            }
        }
        return true;
    }
};
