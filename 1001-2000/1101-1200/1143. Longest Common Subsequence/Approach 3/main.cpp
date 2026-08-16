class Solution {
public:
    int longestCommonSubsequence(
        string text1,
        string text2
    ) {
        int firstLength =
            static_cast<int>(text1.size());

        int secondLength =
            static_cast<int>(text2.size());

        vector<vector<int>> dp(
            firstLength + 1,
            vector<int>(
                secondLength + 1
            )
        );

        for (int first = 1; first <= firstLength; first++) {
            for (int second = 1; second <= secondLength; second++) {
                if (text1[first - 1] == text2[second - 1]) {
                    dp[first][second] =
                        1 +
                        dp[first - 1][second - 1];
                } else {
                    dp[first][second] = max(
                        dp[first - 1][second],
                        dp[first][second - 1]
                    );
                }
            }
        }

        return dp[firstLength][secondLength];
    }
};
