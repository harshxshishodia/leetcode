class Solution {
public:
    bool isMatch(string s, string p) {
        int sLength = static_cast<int>(s.size());
        int pLength = static_cast<int>(p.size());
        vector<vector<bool>> dp(
            sLength + 1,
            vector<bool>(pLength + 1, false)
        );

        dp[0][0] = true;

        for (int j = 1; j <= pLength; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= sLength; i++) {
            for (int j = 1; j <= pLength; j++) {
                if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[sLength][pLength];
    }
};
