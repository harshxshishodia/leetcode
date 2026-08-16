class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = static_cast<int>(coins.size());
        const int INF = 1000000000;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, INF)
        );

        for (int index = 0; index <= n; index++) {
            dp[index][0] = 0;
        }

        for (int index = n - 1; index >= 0; index--) {
            for (int value = 1; value <= amount; value++) {
                dp[index][value] = dp[index + 1][value];

                if (coins[index] <= value &&
                    dp[index][value - coins[index]] != INF) {
                    dp[index][value] = min(
                        dp[index][value],
                        1 + dp[index][value - coins[index]]
                    );
                }
            }
        }

        return dp[0][amount] == INF ? -1 : dp[0][amount];
    }
};
