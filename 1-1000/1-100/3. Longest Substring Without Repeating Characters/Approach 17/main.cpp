// Coordinate-compress the characters, then store last positions in a vector.
// Time: O(n log k), Space: O(k), where k <= 256 is the alphabet size.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<unsigned char> alphabet;
        alphabet.reserve(s.size());
        for (char value : s) {
            alphabet.push_back(static_cast<unsigned char>(value));
        }
        sort(alphabet.begin(), alphabet.end());
        alphabet.erase(unique(alphabet.begin(), alphabet.end()), alphabet.end());

        vector<int> lastSeen(alphabet.size(), -1);
        int left = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            int id = static_cast<int>(
                lower_bound(alphabet.begin(), alphabet.end(), c) - alphabet.begin()
            );
            left = max(left, lastSeen[id] + 1);
            lastSeen[id] = right;
            best = max(best, right - left + 1);
        }

        return best;
    }
};
