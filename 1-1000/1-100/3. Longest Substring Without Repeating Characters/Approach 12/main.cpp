// Store the current unique window as a string and erase through a duplicate.
// Time: O(n^2) worst case because find/erase are linear, Space: O(n).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string window;
        int best = 0;

        for (char c : s) {
            size_t duplicate = window.find(c);
            if (duplicate != string::npos) {
                window.erase(0, duplicate + 1);
            }
            window.push_back(c);
            best = max(best, static_cast<int>(window.size()));
        }

        return best;
    }
};
