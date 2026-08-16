class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1);
        dp[0] = 1;

        for (int coin : coins) {
            for (int value = coin; value <= amount; value++) {
                dp[value] += dp[value - coin];
            }
        }

        return static_cast<int>(dp[amount]);
    }
};
