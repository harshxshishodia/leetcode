class Solution {
public:
    int minDistance(string word1, string word2) {
        int firstLength = static_cast<int>(word1.size());
        int secondLength = static_cast<int>(word2.size());

        vector<vector<int>> dp(
            firstLength + 1,
            vector<int>(secondLength + 1)
        );

        for (int i = 0; i <= firstLength; i++) {
            dp[i][secondLength] =
                firstLength - i;
        }

        for (int j = 0; j <= secondLength; j++) {
            dp[firstLength][j] =
                secondLength - j;
        }

        for (int i = firstLength - 1; i >= 0; i--) {
            for (int j = secondLength - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] =
                        1 + min(
                            dp[i + 1][j],
                            dp[i][j + 1]
                        );
                }
            }
        }

        return dp[0][0];
    }
};
