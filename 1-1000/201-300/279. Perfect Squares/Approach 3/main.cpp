class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int amount = 1; amount <= n; amount++) {
            for (int value = 1; value * value <= amount; value++) {
                dp[amount] = min(
                    dp[amount],
                    1 + dp[amount - value * value]
                );
            }
        }

        return dp[n];
    }
};
