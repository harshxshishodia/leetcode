class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLength = 1;

        for (int left = n - 1; left >= 0; left--) {
            for (int right = left; right < n; right++) {
                if (s[left] == s[right] && (right - left <= 1 || dp[left + 1][right - 1])) {
                    dp[left][right] = true;
                    int length = right - left + 1;

                    if (length > maxLength) {
                        start = left;
                        maxLength = length;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};