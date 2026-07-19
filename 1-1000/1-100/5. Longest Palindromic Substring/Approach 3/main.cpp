class Solution {
    void expand(const string& s, int left, int right, int& start, int& maxLength) {
        int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }

        int length = right - left - 1;

        if (length > maxLength) {
            start = left + 1;
            maxLength = length;
        }
    }

public:
    // O(n^2) | O(1)
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 1;

        for (int center = 0; center < s.size(); center++) {
            expand(s, center, center, start, maxLength);
            expand(s, center, center + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }
};