class Solution {
    int solve(
        const vector<int>& prices,
        int index,
        int canBuy,
        vector<vector<int>>& dp
    ) {
        if (index == static_cast<int>(prices.size())) {
            return 0;
        }

        if (dp[index][canBuy] != -1) {
            return dp[index][canBuy];
        }

        if (canBuy == 1) {
            dp[index][canBuy] = max(
                solve(prices, index + 1, 1, dp),
                -prices[index] + solve(prices, index + 1, 0, dp)
            );
        } else {
            dp[index][canBuy] = max(
                solve(prices, index + 1, 0, dp),
                prices[index] + solve(prices, index + 1, 1, dp)
            );
        }

        return dp[index][canBuy];
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(
            prices.size(),
            vector<int>(2, -1)
        );

        return solve(prices, 0, 1, dp);
    }
};
