// Binary-search the answer and test fixed-length windows with frequencies.
// Time: O(n log n), Space: O(1).
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int high = static_cast<int>(s.size());

        while (low < high) {
            int middle = low + (high - low + 1) / 2;
            if (hasUniqueWindow(s, middle)) {
                low = middle;
            } else {
                high = middle - 1;
            }
        }

        return low;
    }

private:
    bool hasUniqueWindow(const string& s, int length) {
        if (length == 0) return true;

        array<int, 256> frequency{};
        int duplicatedValues = 0;

        for (int i = 0; i < length; ++i) {
            unsigned char c = static_cast<unsigned char>(s[i]);
            if (++frequency[c] == 2) ++duplicatedValues;
        }
        if (duplicatedValues == 0) return true;

        for (int right = length; right < static_cast<int>(s.size()); ++right) {
            unsigned char outgoing = static_cast<unsigned char>(s[right - length]);
            if (frequency[outgoing]-- == 2) --duplicatedValues;

            unsigned char incoming = static_cast<unsigned char>(s[right]);
            if (++frequency[incoming] == 2) ++duplicatedValues;

            if (duplicatedValues == 0) return true;
        }

        return false;
    }
};
