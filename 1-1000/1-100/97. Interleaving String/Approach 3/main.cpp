class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int firstLength = static_cast<int>(s1.size());
        int secondLength = static_cast<int>(s2.size());

        if (firstLength + secondLength != static_cast<int>(s3.size())) {
            return false;
        }

        vector<vector<bool>> dp(
            firstLength + 1,
            vector<bool>(secondLength + 1)
        );

        dp[0][0] = true;

        for (int i = 0; i <= firstLength; i++) {
            for (int j = 0; j <= secondLength; j++) {
                if (i > 0) {
                    dp[i][j] = dp[i][j] ||
                               (dp[i - 1][j] &&
                                s1[i - 1] == s3[i + j - 1]);
                }

                if (j > 0) {
                    dp[i][j] = dp[i][j] ||
                               (dp[i][j - 1] &&
                                s2[j - 1] == s3[i + j - 1]);
                }
            }
        }

        return dp[firstLength][secondLength];
    }
};
