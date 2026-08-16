class Solution {
    int palindrome(const string& s, int left, int right, vector<vector<int>>& dp) {
        if (left >= right) {
            return 1;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        if (s[left] != s[right]) {
            dp[left][right] = 0;
        } else {
            dp[left][right] = palindrome(s, left + 1, right - 1, dp);
        }

        return dp[left][right];
    }

public:
    string longestPalindrome(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int length = n; length >= 1; length--) {
            for (int start = 0; start + length <= n; start++) {
                int end = start + length - 1;

                if (palindrome(s, start, end, dp)) {
                    return s.substr(start, length);
                }
            }
        }

        return "";
    }
};
