class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(
            stones.begin(),
            stones.end(),
            0
        );

        int target =
            total / 2;

        int n =
            static_cast<int>(stones.size());

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(
                target + 1
            )
        );

        dp[0][0] = true;

        for (int index = 1; index <= n; index++) {
            dp[index][0] = true;

            for (int sum = 1; sum <= target; sum++) {
                dp[index][sum] =
                    dp[index - 1][sum];

                if (stones[index - 1] <= sum) {
                    dp[index][sum] =
                        dp[index][sum] ||
                        dp[index - 1][sum - stones[index - 1]];
                }
            }
        }

        for (int sum = target; sum >= 0; sum--) {
            if (dp[n][sum]) {
                return total - 2 * sum;
            }
        }

        return total;
    }
};
