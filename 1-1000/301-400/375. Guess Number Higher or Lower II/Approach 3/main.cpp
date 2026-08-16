class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(
            n + 2,
            vector<int>(n + 2)
        );

        for (int length = 2; length <= n; length++) {
            for (int left = 1; left + length - 1 <= n; left++) {
                int right = left + length - 1;
                dp[left][right] = numeric_limits<int>::max();

                for (int guess = left; guess <= right; guess++) {
                    int cost = guess + max(
                        dp[left][guess - 1],
                        dp[guess + 1][right]
                    );

                    dp[left][right] = min(
                        dp[left][right],
                        cost
                    );
                }
            }
        }

        return dp[1][n];
    }
};
