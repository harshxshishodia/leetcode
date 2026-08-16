class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1000000000;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int coin : coins) {
            for (int value = coin; value <= amount; value++) {
                if (dp[value - coin] != INF) {
                    dp[value] = min(
                        dp[value],
                        1 + dp[value - coin]
                    );
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};
