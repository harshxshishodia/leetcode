class Solution {
    pair<int, int> expand(const string& s, int left, int right) {
        while (left >= 0 &&
               right < static_cast<int>(s.size()) &&
               s[left] == s[right]) {
            left--;
            right++;
        }

        return {left + 1, right - left - 1};
    }

public:
    string longestPalindrome(string s) {
        int bestStart = 0;
        int bestLength = 1;

        for (int center = 0; center < static_cast<int>(s.size()); center++) {
            auto odd = expand(s, center, center);
            auto even = expand(s, center, center + 1);

            if (odd.second > bestLength) {
                bestStart = odd.first;
                bestLength = odd.second;
            }

            if (even.second > bestLength) {
                bestStart = even.first;
                bestLength = even.second;
            }
        }

        return s.substr(bestStart, bestLength);
    }
};
