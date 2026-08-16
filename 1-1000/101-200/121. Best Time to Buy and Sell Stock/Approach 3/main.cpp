class Solution {
    int solve(vector<int>& prices, int index, int canBuy, vector<vector<int>>& dp) {
        if (index == static_cast<int>(prices.size())) {
            return 0;
        }

        if (dp[index][canBuy] != -1) {
            return dp[index][canBuy];
        }

        if (canBuy == 1) {
            int skip = solve(prices, index + 1, 1, dp);
            int buy = -prices[index] + solve(prices, index + 1, 0, dp);
            dp[index][canBuy] = max(skip, buy);
        } else {
            int skip = solve(prices, index + 1, 0, dp);
            int sell = prices[index];
            dp[index][canBuy] = max(skip, sell);
        }

        return dp[index][canBuy];
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};
