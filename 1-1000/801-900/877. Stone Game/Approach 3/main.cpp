class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = static_cast<int>(piles.size());

        vector<vector<int>> dp(
            n,
            vector<int>(n)
        );

        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        for (int length = 2; length <= n; length++) {
            for (int left = 0;
                 left + length <= n;
                 left++) {
                int right =
                    left + length - 1;

                dp[left][right] = max(
                    piles[left] -
                    dp[left + 1][right],
                    piles[right] -
                    dp[left][right - 1]
                );
            }
        }

        return dp[0][n - 1] > 0;
    }
};
