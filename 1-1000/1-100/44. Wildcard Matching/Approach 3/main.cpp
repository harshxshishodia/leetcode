class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[m][n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (p[j] == '*')
                    dp[i][j] = dp[i][j + 1] || (i < m && dp[i + 1][j]);
                else
                    dp[i][j] = i < m && (s[i] == p[j] || p[j] == '?') && dp[i + 1][j + 1];
            }
        }

        return dp[0][0];
    }
};