class Solution {
public:
    int minCapability(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        const int INF =
            numeric_limits<int>::max();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(
                k + 1,
                INF
            )
        );

        for (int index = 0; index <= n; index++) {
            dp[index][0] = 0;
        }

        for (int index = 1; index <= n; index++) {
            for (int robbed = 1;
                 robbed <= k;
                 robbed++) {
                dp[index][robbed] =
                    dp[index - 1][robbed];

                int previous =
                    index >= 2
                        ? dp[index - 2][robbed - 1]
                        : (
                            robbed == 1
                                ? 0
                                : INF
                        );

                if (previous != INF) {
                    dp[index][robbed] = min(
                        dp[index][robbed],
                        max(
                            previous,
                            nums[index - 1]
                        )
                    );
                }
            }
        }

        return dp[n][k];
    }
};
