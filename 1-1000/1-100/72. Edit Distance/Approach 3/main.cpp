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
            dp[i][0] = i;
        }

        for (int j = 0; j <= secondLength; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= firstLength; i++) {
            for (int j = 1; j <= secondLength; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i][j - 1],
                        dp[i - 1][j],
                        dp[i - 1][j - 1]
                    });
                }
            }
        }

        return dp[firstLength][secondLength];
    }
};
