class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = static_cast<int>(coins.size());

        vector<vector<unsigned long long>> dp(
            n + 1,
            vector<unsigned long long>(amount + 1)
        );

        for (int index = 0; index <= n; index++) {
            dp[index][0] = 1;
        }

        for (int index = n - 1; index >= 0; index--) {
            for (int value = 1; value <= amount; value++) {
                dp[index][value] = dp[index + 1][value];

                if (coins[index] <= value) {
                    dp[index][value] +=
                        dp[index][value - coins[index]];
                }
            }
        }

        return static_cast<int>(dp[0][amount]);
    }
};
