class Solution {
public:
    int numRollsToTarget(
        int n,
        int k,
        int target
    ) {
        const int MOD = 1000000007;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(
                target + 1
            )
        );

        dp[0][0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            for (int sum = 1; sum <= target; sum++) {
                long long ways = 0;

                for (int face = 1;
                     face <= k &&
                     face <= sum;
                     face++) {
                    ways +=
                        dp[dice - 1][sum - face];
                }

                dp[dice][sum] =
                    static_cast<int>(
                        ways % MOD
                    );
            }
        }

        return dp[n][target];
    }
};
