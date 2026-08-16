class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = static_cast<int>(prices.size());
        vector<vector<int>> dp(n + 1, vector<int>(2));

        for (int index = n - 1; index >= 0; index--) {
            dp[index][1] = max(dp[index + 1][1], -prices[index] + dp[index + 1][0]);
            dp[index][0] = max(dp[index + 1][0], prices[index]);
        }

        return dp[0][1];
    }
};
