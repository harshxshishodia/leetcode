// Keep the current unique window in a queue plus a membership table.
// Time: O(n), Space: O(min(n, 256)).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<unsigned char> window;
        array<bool, 256> seen{};
        int best = 0;

        for (char value : s) {
            unsigned char c = static_cast<unsigned char>(value);
            while (seen[c]) {
                seen[window.front()] = false;
                window.pop();
            }
            window.push(c);
            seen[c] = true;
            best = max(best, static_cast<int>(window.size()));
        }

        return best;
    }
};
