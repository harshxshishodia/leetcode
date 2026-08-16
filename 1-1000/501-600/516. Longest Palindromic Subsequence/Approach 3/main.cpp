class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<int>> dp(
            n,
            vector<int>(n)
        );

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int left = n - 1; left >= 0; left--) {
            for (int right = left + 1; right < n; right++) {
                if (s[left] == s[right]) {
                    dp[left][right] =
                        2 + dp[left + 1][right - 1];
                } else {
                    dp[left][right] = max(
                        dp[left + 1][right],
                        dp[left][right - 1]
                    );
                }
            }
        }

        return dp[0][n - 1];
    }
};
