class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int firstLength = static_cast<int>(s1.size());
        int secondLength = static_cast<int>(s2.size());

        vector<vector<int>> dp(
            firstLength + 1,
            vector<int>(secondLength + 1)
        );

        for (int i = firstLength - 1; i >= 0; i--) {
            dp[i][secondLength] =
                dp[i + 1][secondLength] +
                static_cast<unsigned char>(s1[i]);
        }

        for (int j = secondLength - 1; j >= 0; j--) {
            dp[firstLength][j] =
                dp[firstLength][j + 1] +
                static_cast<unsigned char>(s2[j]);
        }

        for (int i = firstLength - 1; i >= 0; i--) {
            for (int j = secondLength - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] =
                        dp[i + 1][j + 1];
                } else {
                    dp[i][j] = min(
                        static_cast<unsigned char>(s1[i]) +
                        dp[i + 1][j],
                        static_cast<unsigned char>(s2[j]) +
                        dp[i][j + 1]
                    );
                }
            }
        }

        return dp[0][0];
    }
};
